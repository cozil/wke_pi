#include "stdafx.h"
#include "PiMathUnit.h"
#include <limits>

Pi_NameSpace_Begin
bool FlowBigger(double n1, double n2)
{
	return abs(n1 - n2) > std::numeric_limits<float>::epsilon();
}

bool FlowEqual(double n1, double n2)
{
	return abs(n1 - n2) < std::numeric_limits<float>::epsilon();
}


SIZE CPiMath::GetKeepRadio(const SIZE& szSrc, const SIZE& szLimit)
{
	/************************************************************************
	�ȱ�����
	�Ŵ������
	1. ͼƬ�����ߴ�С�����Ƴߴ���ԭͼ
	2. ��Сʱ�� ȡ������ű����ϴ��һ����Ϊ���ű�
	3. �Ŵ�ʱ�� ȡ������С��һ����Ϊ���ű�
	4. һ�߷Ŵ� һ����С�� ����С

	��С�� radio > 1
	�Ŵ� radio < 1,
	************************************************************************/
	SIZE szBig = { 0, 0 };
	float fRadioCx = 1.0 * szSrc.cx / szLimit.cx;
	float fRadioCy = 1.0 * szSrc.cy / szLimit.cy;
	float nRadio = 0;
	bool bZoomOut = (fRadioCx > 1 || fRadioCy > 1);
	SIZE szDist = { 0 };
	if (bZoomOut)
	{
		nRadio = max(fRadioCx, fRadioCy);
	}
	else
	{
		nRadio = max(fRadioCx, fRadioCy);	//�Ŵ�ʱ�� ����Ϊ0~1��Χ,  Լ��ı���ϵ�����ֵС
	}
	szDist.cx = szSrc.cx / nRadio;
	szDist.cy = szSrc.cy / nRadio;
	return szDist;
}

Pi_NameSpace_End