#include "pch.h"
#include "Header.h"
#include <vector>
#include <unordered_map>
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	본인보다 작은 원소들의 갯수

	
	이거 벡터에 넣고 순번 같이 pair로 저장한다음 정렬
	정렬순으로 번호 매기고(앞과 중복이면 중복번호 부여)하고
	다시 순번순으로 정렬해서 쭉 출력하면 더 빠르다.
	*/

	int iSize;
	CIN >> iSize;

	int iInput;
	vector<int> vecNums;
	unordered_map<int, int> mapRank;
	priority_queue<int, vector<int>, greater<int>> stlNums;
	for (int i = 0; i < iSize; ++i)
	{
		CIN >> iInput;
		vecNums.push_back(iInput);
		mapRank[iInput] = 0;
	}
	for (auto iter = mapRank.begin(); iter != mapRank.end(); ++iter)
	{
		stlNums.push(iter->first);
	}

	int Temp = stlNums.size();
	for (int i = 0; i < Temp; ++i)
	{
		mapRank[stlNums.top()] = i;
		stlNums.pop();
	}


	for (int i = 0; i < iSize; ++i)
	{
		cout << mapRank[vecNums[i]] << ' ';
	}
}