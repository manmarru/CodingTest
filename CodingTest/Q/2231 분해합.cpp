#include "pch.h"
#include "Header.h"
#include <limits>

void Solve(ifstream* _pLoadStream)
{
	//n�� ���� ���� ������ ���ϱ�

	//�� �ڸ� ���ڸ� �� ���ؼ� ���� �� �ִ� ���ڴ� 9, 99, 999, ...
	//���� üũ�ؾ� �ϴ� ���� ������ 9, 18, 27, ...
	int answer = INT_MAX;


	string strInput;
	(*_pLoadStream) >> strInput;

	int iTarget = stoi(strInput);
	int iDigits = strInput.size();

	if (iDigits == 1) // ���ڸ� ����
	{
		if (iTarget % 2 == 0)
			cout << iTarget / 2 << endl;
		else
			cout << 0 << endl;
		return;
	}

	int iChecking = (iDigits - 1) * 9;

	string singlenum;
	int iSum(0);	// �����
	int iCurrentNum(0); // �����ϰ��ִ� ����
	int iCurrentNumCopy(0);
	for (int i = 1; i < iTarget - 1; i++)
	{
		iSum = 0;
		iCurrentNumCopy = iCurrentNum = i;
		iSum += iCurrentNum;
		//�� �ڸ��� ���ϱ�
		while (iCurrentNumCopy >= 1)
		{
			iSum += iCurrentNumCopy % 10;
			iCurrentNumCopy /= 10;
		}

		if (iTarget == iSum)
		{
			if (answer > iCurrentNum)
				answer = iCurrentNum;
		}
	}
	
	
	if (INT_MAX == answer)
		cout << 0 << endl;
	else
		cout << answer << endl;
	
	//198�� ���´� 1 + 9 + 8 + 198
}