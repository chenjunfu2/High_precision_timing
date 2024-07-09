#pragma once

#include <Windows.h>

typedef long double LONG_DOUBLE;

typedef struct htimer
{
	LARGE_INTEGER freq;
	LARGE_INTEGER begin_time;
	LARGE_INTEGER end_time;
}HTIMER;

#define INITTIMER(HTIMER_STRUCT)	(QueryPerformanceFrequency(&HTIMER_STRUCT.freq))//��ʼ�����ܼ������������ṹ��ɼ̳�
#define STARTTIME(HTIMER_STRUCT)	(QueryPerformanceCounter(&HTIMER_STRUCT.begin_time))//��ʼ��ʱ
#define ENDINTIME(HTIMER_STRUCT)	(QueryPerformanceCounter(&HTIMER_STRUCT.end_time))//������ʱ


#define RESULTS_S(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//���ؼ�ʱ���������SΪ��λ
#define RESULTS_MS(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//���ؼ�ʱ���������MSΪ��λ
#define RESULTS_US(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//���ؼ�ʱ���������USΪ��λ
#define RESULTS_NS(HTIMER_STRUCT)	((LONG_DOUBLE)((LONG_DOUBLE)(HTIMER_STRUCT.end_time.QuadPart - HTIMER_STRUCT.begin_time.QuadPart) * (LONG_DOUBLE)1000000000.00 / (LONG_DOUBLE)HTIMER_STRUCT.freq.QuadPart))//���ؼ�ʱ���������NSΪ��λ

#define PRINT_TIME(HTIMER_STRUCT,UNIT,PRECISION)	(printf(#HTIMER_STRUCT":%."#PRECISION"lf"#UNIT"\n",RESULTS_##UNIT(HTIMER_STRUCT)))//��ӡ��ʱ���  ������ʱ��ṹ�� ʱ�䵥λ ����

