#include "pch.h"
#include "Header.h"
#include <vector>
#include <unordered_map>
#include <queue>

void Solve(ifstream* _pLoadStream)
{
	/*
	���κ��� ���� ���ҵ��� ����

	
	�̰� ���Ϳ� �ְ� ���� ���� pair�� �����Ѵ��� ����
	���ļ����� ��ȣ �ű��(�հ� �ߺ��̸� �ߺ���ȣ �ο�)�ϰ�
	�ٽ� ���������� �����ؼ� �� ����ϸ� �� ������.
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