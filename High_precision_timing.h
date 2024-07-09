#pragma once

#include <Windows.h>

typedef long double LONG_DOUBLE;

typedef struct htimer
{
	LARGE_INTEGER freq;
	LARGE_INTEGER begin_time;
	LARGE_INTEGER end_time;
}HTIMER;

#define INITTIMER(HTIMER_STRUCT)	(QueryPerformanceFrequency(&HTIMER_STRUCT.freq))//初始化性能计算器，后续结构体可继承
#define STARTTIME(HTIMER_STRUCT)	(QueryPerformanceCounter(&HTIMER_STRUCT.begin_time))//开始计时
#define ENDINTIME(HTIMER_STRUCT)	(QueryPerformanceCounter(&HTIMER_STRUCT.end_time))//结束计时


#define RESULTS_S(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//返回计时器间隔，以S为单位
#define RESULTS_MS(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//返回计时器间隔，以MS为单位
#define RESULTS_US(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//返回计时器间隔，以US为单位
#define RESULTS_NS(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000000000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//返回计时器间隔，以NS为单位

#define PRINT_TIME(HTIMER_STRUCT,UNIT,PRECISION)	(printf(#HTIMER_STRUCT":%."#PRECISION"lf"#UNIT"\n",RESULTS_##UNIT(HTIMER_STRUCT)))//打印计时间隔  参数：时间结构体 时间单位 精度

