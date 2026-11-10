#pragma once

// 定位算法选择。全工程只认这一个宏。
//
//   SBL_ALGO_TRIANGULATION  经典三角定位（两基准站水平角前方交会）
//   SBL_ALGO_SLANT_RANGE    两基准站斜距 + 基准站坐标 + 移动站高度，求平面位置
//
// 切换方式（任选其一）：
//   1. 改本文件中 SBL_POSITION_ALGO 的默认值
//   2. 编译选项 -DSBL_POSITION_ALGO=1 或 -DSBL_POSITION_ALGO=2
//   3. CMake：cmake -DSBL_POSITION_ALGO=2 ..

#define SBL_ALGO_TRIANGULATION 1
#define SBL_ALGO_SLANT_RANGE 2

#ifndef SBL_POSITION_ALGO
#define SBL_POSITION_ALGO SBL_ALGO_TRIANGULATION
#endif

#if (SBL_POSITION_ALGO != SBL_ALGO_TRIANGULATION) && \
    (SBL_POSITION_ALGO != SBL_ALGO_SLANT_RANGE)
#error "SBL_POSITION_ALGO must be SBL_ALGO_TRIANGULATION (1) or SBL_ALGO_SLANT_RANGE (2)"
#endif
