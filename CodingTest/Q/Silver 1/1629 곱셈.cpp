#include "pch.h"
#include "Header.h"
#include <queue>



void Solve(ifstream* _pLoadStream)
{
	/*
	큰 숫자의 거듭제곱 A^B % c 계산
	이집트 곱셈법 + 정수론에 나오는 모듈연산 정리

	B = Q + W 일 떄
	A^B % C = ((A^Q % C) * (A^W % C)) % C
	*/

	unsigned long long int InputA, InputB, InputC;
	unsigned long long int Result{ 1 };
	CIN >> InputA >> InputB >> InputC;
	InputA %= InputC;
	queue<bool> BinBit;

	
	//b를 이진수로 나타내기
	while (InputB > 1)
	{
		BinBit.push(InputB % 2);
		InputB /= 2;
	}
	BinBit.push(InputB);

	// 제곱하기
	unsigned long long CurrA{ InputA };
	while (!BinBit.empty())
	{
		if(BinBit.front())
			Result *= CurrA;
		Result %= InputC;
		BinBit.pop();

		CurrA *= CurrA;
		CurrA %= InputC;
	}
	cout << Result << endl;
}