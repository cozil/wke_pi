#pragma once
#include <limits>
#include "../PiTypeDef.h"
#include <wtypes.h>

Pi_NameSpace_Begin
const int NUM_INT_DIGIT_LENGTH = 30;//�ַ�����ʽ�����ݴ�С���֧�ֵ�λ��

const UNLONG NUM_FILE_SIZE_RATE = 1024;                     //�ļ���С��λ����
const UNLONG NUM_FILE_SIZE_1K = 1024;
const UNLONG NUM_FILE_SIZE_1M = NUM_FILE_SIZE_1K * NUM_FILE_SIZE_RATE;
const UNINT64 NUM_FILE_SIZE_1G = NUM_FILE_SIZE_1M * NUM_FILE_SIZE_RATE;
const UNINT64 NUM_FILE_SIZE_1T = NUM_FILE_SIZE_1G * NUM_FILE_SIZE_RATE;

const int NUM_PERCENT_MAX = 100;  //�ٷֱ����ֵ


//ʱ��
const UNLONG NUM_TIME_RATE = 60;

#define SECOND_TO_NANOSECOND(n) ((n)*1000*1000*1000)        //�� -> ����
#define SECOND_TO_MILLISECOND(n) ((n)*1000)        //�� -> ����
#define MILLISECOND_TO_NANOSECOND(n) ((n)*1000*1000)        //���� -> ����
#define MILLISECOND_TO_NANOSECOND100(n) ((n)*1000*10)        //���� -> 100����

#define NANOSECOND100_TO_NANOSECOND(n) ((n)*100)            //100����ת����
#define NANOSECOND100_TO_MILLISECOND(n) ((n)/10 / 1000)        //100���� ת ����
#define INT_TO_FLOAT(n) (1.0f * (n))                        //����ת�ɸ�����, �������������ʱ, �������ߵľ���
#define PERCENT_TO_DIGIT(n) ( (n) /100.0f)
#define DIGIT_TO_PERCENT(n) ( (n) * 100.0f)
//#define TO_DOUBLE(1.0df * n)
//�ļ���Сת��
#define BYTE_TO_KB(n)       ( INT_TO_FLOAT((n)) / ( 2<<(10-1) )) // -1: 10�η�Ϊ �ٳ���2 = 1024
#define BYTE_TO_MB(n)       ( INT_TO_FLOAT((n)) / ( 2<<(20-1) ))
#define BYTE_TO_GB(n)       ( INT_TO_FLOAT((n)) / ( 2<<(30-1) ))

//ʱ��
#define SECOND_TO_MINUTE(n) (n / NUM_TIME_RATE)
#define SECOND_TO_HOUR(n) (n / NUM_TIME_RATE / NUM_TIME_RATE)

#define MINUTE_TO_HOUR(n) (n / NUM_TIME_RATE)
#define MINUTE_TO_SECOND(n) (n * NUM_TIME_RATE)
#define MINUTE_TO_MILLISECOND(n) (n * NUM_TIME_RATE * 1000)

#define HOUR_TO_MINUTE(n) (n * NUM_TIME_RATE)
#define HOUR_TO_SECOND(n) (n * NUM_TIME_RATE * NUM_TIME_RATE)



//ȥ��ħ��
#define  INDEX_TO_COUNT(n) ((n) + 1)
#define  COUNT_TO_INDEX(n) ((n) - 1)

//λ����
//��һ����ֵ�����Ƴ�ĳ����ʶλ�Ĳ���
#define TakeOut(nInt, nErase) (nInt&~nErase)

bool FlowBigger(double n1, double n2);
bool FlowEqual(double n1, double n2);


class CPiMath
{
public:
	CPiMath();
	~CPiMath();
public:
	/************************************************************************
	fun:	��ȡ�ȱ�����������ź������С
	param:
	memo:
	************************************************************************/
	static SIZE GetKeepRadio(const SIZE& szSrc, const SIZE& szLimit);
protected:
private:
};

Pi_NameSpace_End
