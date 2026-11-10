# 定位程序的 MQTT

`sbl_position_demo` 做两件事：订阅评估程序的 `sbl/evaluate`，解算后把终端上的定位结果发到 `sbl/position`。

坐标与评估程序一致：**+X 右舷、+Y 船艏、+Z 向上**，单位米。

## 连接

| 项 | 值 |
| --- | --- |
| 地址 | `127.0.0.1:1883`，可用 `MQTT_HOST`、`MQTT_PORT` 修改 |
| 协议 | MQTT 3.1.1，无 TLS、无用户名密码 |
| 客户端 ID | `sbl-position` |
| Clean session | true |
| Keepalive | 60 s |
| 订阅 | `sbl/evaluate`，QoS 0 |
| 发布 | `sbl/position`，QoS 0，不保留 |
| 行为 | 连上后一直收。每解算一条就发一条。断线后进程退出，退出码 2 |

评估程序大约每秒重复最近一次评估。接收端对每一条都解算并转发，`seq` 沿用评估报文的序号。

订阅本程序发出的结果：

```text
mosquitto_sub -h 127.0.0.1 -p 1883 -t sbl/position -V mqttv311
```

## 从评估报文里取什么

接受 `schema` 为 `sbl.evaluate.v1` 或 `sbl.evaluate.v2` 的对象。

基站和斜距的对应关系：

1. 在 `results` 里取 `ok` 为 true、且 `role` 为 `robot` 的那一条。没有 `robot` 时用第一条成功结果。
2. 这条结果的 `ranges` 里，只保留 `used` 和 `los` 都为 true 的斜距。`range_m` 是几何斜距，米。
3. 用 `receiver_id` 到 `layout.receivers` 里找 Type A 的 `x`、`y`、`z`。
4. 顺序沿用 `layout.receivers` 的数组顺序，跳过没有可用斜距的站。
5. `stations 2` 时取已知高度，单位米。`sbl.evaluate.v2` 把机器人的 x、y 留在发布端，高度在该条结果的 `z`，`layout.transmitters` 里同一信标也只有 `z`。接收端先用结果的 `z`，没有再用信标的 `z`，再没有才用 `position` 的第三个数。

`stations 3` 取前 3 座，写入 A、B、C。`stations 2` 取前 2 座，写入 A、B。条数不够，或双站时没有高度，就跳过这一条报文，继续等下一条，这时不发 `sbl/position`。

双站先在终端打出 `height`，它就是报文里的已知高度，解算位置的 z 与它相同。三站的 `height` 是交点解出的 z。

下面这些仍来自配置文件，不从评估报文覆盖：

| 配置 | 作用 |
| --- | --- |
| `stations` | 选三站三角定位或双站加已知高度 |
| `height_select` | 三站时在高低两个交点里留一个 |
| `side_select` | 双站时基线左/右侧 |
| `slant_range_error`、`base_error_x/y/z` | 本程序自己的极限误差和 1σ |

评估报文里的 `layout.mode`、`sigma_r`、`type_a_site_sigma` 和 `results[].sigma` 不参与这次解算。发射信标的 x、y 仍是评估真值，不当作定位结果；只有它的 z 在双站时当作已知高度。

`stations 2` 时按 `layout.receivers` 顺序只用前 2 座已使用的直视站。`stations 3` 再用第 3 座。`occluded_links` 不单独读。被挡住的斜距在 `ranges` 里已经是 `los: false` 或 `used: false`，接收端会丢掉。

## 定位结果发布

主题 `sbl/position`。载荷是 UTF-8 JSON，一个对象一条消息，无换行、无空格。`schema` 固定为 `sbl.position.v1`。解算失败时也发，只带状态和已有的高度，不带位置和误差。

下面是双站一次成功解算的结构，数字与终端同一条结果一致：

```json
{
  "schema": "sbl.position.v1",
  "seq": 116,
  "transmitter_id": "tx-1",
  "algorithm": "slant_range",
  "status": "ok",
  "message": "selected the left solution",
  "solutions": 1,
  "height": 7.092,
  "position": [24.1, -34.579, 7.092],
  "combinations": 256,
  "succeeded": 256,
  "max_error_x": 1.995325,
  "max_error_y": 1.187627,
  "sigma_x": 0.494692,
  "sigma_y": 0.310878
}
```

键的先后不参与判读。线上报文不换行。

| 字段 | 类型 | 含义 |
| --- | --- | --- |
| `schema` | string | 固定 `sbl.position.v1` |
| `seq` | int | 沿用所收评估报文的 `seq` |
| `transmitter_id` | string | 这次解算的发射信标 |
| `algorithm` | string | `triangulation` 或 `slant_range` |
| `status` | string | `ok`、`invalid_input`、`no_solution` 等，与终端 `status` 相同 |
| `message` | string | 与终端 `message` 相同 |
| `solutions` | int | 输出的位置个数。正常为 1 |
| `height` | number | 米。双站是已知高度，三站是解出的 z。没有高度时不出现 |
| `position` | array | `[x, y, z]`，米。无解时不出现 |
| `combinations` | int | 极限法端点组合数。未进入误差评估时不出现 |
| `succeeded` | int | 组合里解算成功的点数 |
| `max_error_x`、`max_error_y` | number | 端点组合后最大值与最小值之差的绝对值，米 |
| `max_error_z` | number | 仅三站出现 |
| `sigma_x`、`sigma_y` | number | 标称位置处的 1σ，米 |
| `sigma_z` | number | 仅三站出现 |

`succeeded` 为 0 时不带 `max_error_*` 和 `sigma_*`，终端同时打印 `uncertainty: unavailable`。协方差不可用时仍带 `max_error_*`，不带 `sigma_*`，终端打印 `sigma: unavailable`。
