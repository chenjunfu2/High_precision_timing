#include "High_precision_timing.h"

#include <stdio.h>
#include <limits.h>

#define COUNT UINT_MAX/64

int main(void)
{
	HTIMER for_time;
	INITTIMER(for_time);//第一次初始化，后续新结构体可直接继承freq

	STARTTIME(for_time);
	for (unsigned long long i = 0; i < COUNT; ++i)
	{

	}
	ENDINTIME(for_time);
	PRINT_TIME(for_time, MS, 4);


	unsigned long long k;

	HTIMER add{ .freq = for_time.freq };//继承性能计数器频率freq
	STARTTIME(add);
	k = 1;
	for (unsigned long long i = 0; i < COUNT; ++i)
	{
		k += 1145;
	}
	ENDINTIME(add);
	PRINT_TIME(add, MS, 4);


	HTIMER mul{ .freq = for_time.freq };//继承性能计数器频率freq
	STARTTIME(mul);
	k = 1;
	for (unsigned long long i = 0; i < COUNT; ++i)
	{
		k *= 1145;
	}
	ENDINTIME(mul);
	PRINT_TIME(mul, MS, 4);

	return 0;
}