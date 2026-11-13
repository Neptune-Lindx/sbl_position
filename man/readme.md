# 编译与操作

本工程用 C++17 和 CMake 3.16 及以上编译。在仓库根目录执行下面的命令。算法原理见 [triangulation.md](triangulation.md)。

## 编译

一次编译同时包含两套定位算法，运行时由配置文件里的 `stations` 选择：

```bash
cmake -S . -B build
cmake --build build
```

生成两个程序：

| 程序 | 作用 |
|---|---|
| `build/sbl_position_demo` | 读配置中的算法和误差，从 MQTT 取基站与斜距并解算 |
| `build/sbl_range_check` | 用基站和已知流动站核对三条斜距 |

只重编其中一个：

```bash
cmake --build build --target sbl_position_demo
cmake --build build --target sbl_range_check
```

## 切换算法

在 `config/triangulation.conf` 里改 `stations`，不用重新编译。

| `stations` | 算法 | 配置里还需要 | MQTT 提供 |
|---|---|---|---|
| `3` | 三站斜距三角定位 | `height_select` | 已完成站号 1、2、3 的坐标和斜距 |
| `2` | 双站斜距加已知高度 | `side_select` | 两座有效已完成站的坐标和斜距，以及发射信标的 z |

`height_select` 取 `higher` 或 `lower`。`side_select` 取 `left` 或 `right`，`left` 是水平面内沿 A→B 的左侧。另一种算法用到的配置项可以留在文件里，程序只读取当前 `stations` 需要的项。基站坐标和斜距不写在配置里，见 [mqtt.md](mqtt.md)。

## 运行定位

先让评估程序把 `sbl/evaluate` 发到本机 `127.0.0.1:1883`，再在仓库根目录执行。省略路径时使用 `config/triangulation.conf`：

```bash
./build/sbl_position_demo
./build/sbl_position_demo config/triangulation.conf
```

程序连上 Broker 后一直等待报文。基站站号见 [base_id.md](base_id.md)。三站用已完成的 1、2、3 号。双站每条报文在已完成的站里取 Y 坐标之差绝对值最大的两座有效站，站号较小的作为 A。有效站不足，或所需站号还没确认时，不发定位结果。可以解算时，用其中的斜距和高度解算一次，在终端打印，并按 `sbl.position.v1` 发到主题 `sbl/position`。地址可用环境变量 `MQTT_HOST`、`MQTT_PORT` 修改。字段见 [mqtt.md](mqtt.md)。

`stations 3` 时按 `height_select` 输出一个位置，并单独打出解出的 `height`。`stations 2` 时流动站高度用报文里对应发射信标的 `z`，先打出这个 `height`，再按 `side_select` 输出基线一侧的一个位置。

两种模式都要配置误差界限，单位米：

| 配置项 | 含义 |
|---|---|
| `slant_range_error` | 每条斜距的误差。极限法里是界限，协方差里是 1σ |
| `base_error_x`、`base_error_y`、`base_error_z` | 每个基站对应坐标分量的误差，两种评估共用 |

程序同时输出两种结果。`max_error_x/y/z` 是端点组合后最大值与最小值之差的绝对值。`sigma_x/y/z` 是标称位置处线性化协方差的 1σ。三站输出 x、y、z。双站只输出 x、y。计算思想见 [triangulation.md](triangulation.md) 的「定位误差评估」。

配置打不开、缺项或数值无法解析时退出码为 2。Broker 还没起来，或收发中途断开时，每 2 秒重试，不退出。单条报文无法解算时打印错误并继续等待下一条。

## 运行斜距核对

`sbl_range_check` 从配置文件读取三个基站、已知流动站和三条已知斜距，算出几何斜距后再比较。坐标和斜距的单位都是米。省略路径时使用 `config/range_check.conf`。

```bash
./build/sbl_range_check
./build/sbl_range_check config/range_check.conf
```

| 配置项 | 含义 |
|---|---|
| `base_a`、`base_b`、`base_c` | 三个基站坐标 |
| `rover` | 已知流动站坐标 |
| `slant_range_a`、`slant_range_b`、`slant_range_c` | 三条已知斜距 |
| `tolerance` | 允许的最大偏差，米。省略时为 `0.001` |

样例配置中流动站是 (3, 4, 5)，三条已知斜距是 `sqrt(50)`、`9`、`sqrt(29)`，结果应为通过。三条偏差都不超过容差时退出码为 0，否则为 1。配置打不开、缺项或数值无法解析时退出码为 2。帮助信息：

```bash
./build/sbl_range_check --help
```
