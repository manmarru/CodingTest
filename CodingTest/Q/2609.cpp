#include "pch.h"
#include "2609.h"


void Solve(ifstream* pLoadStream)
{
	//�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ���
	//gcd, lcm ������ ���
	int iInput1(0), iInput2(0);
	int iCopy1(0), iCopy2(0);
	int iGcd(0), iLcm(0);
	(*pLoadStream) >> iInput1 >> iInput2;
	iCopy1 = iInput1;
	iCopy2 = iInput2;
	if (iCopy1 < iCopy2)
		swap(iCopy1, iCopy2);
	//a >= b �϶�
	//gcd(a, b) = gcd(b, b mod a) = gcd(b, a % b)
	while (0 != iCopy1 && 0 != iCopy2)
	{
		iCopy1 %= iCopy2;
		if (iCopy1 < iCopy2)
			swap(iCopy1, iCopy2);
	}
	iGcd = iCopy1;

	cout << iGcd << endl;

	iLcm = (iInput1 * iInput2) / iGcd;
	cout << iLcm << endl;

}