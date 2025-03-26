#include "pch.h"
#include "Header.h"
#include <limits>

void Solve(ifstream* _pLoadStream)
{
	//n의 가장 작은 생성자 구하기

	//각 자리 숫자를 다 더해서 만들 수 있는 숫자는 9, 99, 999, ...
	//따라서 체크해야 하는 숫자 갯수는 9, 18, 27, ...
	int answer = INT_MAX;


	string strInput;
	(*_pLoadStream) >> strInput;

	int iTarget = stoi(strInput);
	int iDigits = strInput.size();

	if (iDigits == 1) // 한자리 숫자
	{
		if (iTarget % 2 == 0)
			cout << iTarget / 2 << endl;
		else
			cout << 0 << endl;
		return;
	}

	int iChecking = (iDigits - 1) * 9;

	string singlenum;
	int iSum(0);	// 계산결과
	int iCurrentNum(0); // 분해하고있는 숫자
	int iCurrentNumCopy(0);
	for (int i = 1; i < iTarget - 1; i++)
	{
		iSum = 0;
		iCurrentNumCopy = iCurrentNum = i;
		iSum += iCurrentNum;
		//각 자릿수 더하기
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
	
	//198이 나온다 1 + 9 + 8 + 198
}