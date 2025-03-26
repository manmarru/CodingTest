#pragma once
#include "pch.h"
#include "Header.h"
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	입출력최적화;
	/*
	n개 카드뭉치를
	지우고
	맨 아래로 보내는걸 반복
	마지막 남는 카드를 반환
	*/

	/* 수학으로 풀기
	input 보다 작고 가장 큰 제곱을 구함 ...(i
	(input - i) * 2 = 정답
	*/
	int iInput;
	*_pLoadStream >> iInput;
	if (iInput == 1)
	{
		cout << 1 << endl;
		return;
	}

	queue<int> queueNums;
	for (int i = 1; i <= iInput; ++i)
	{
		queueNums.push(i);
	}

	while(queueNums.size() != 1)
	{
		queueNums.pop();
		queueNums.push(queueNums.front());
		queueNums.pop();
	}
	cout << queueNums.front() << endl;


}