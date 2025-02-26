#include "pch.h"
#include "Header.h"
#include <map>
#include <vector>
#include <queue>

void Solve(ifstream* pLoadStream)
{
	/*
	������ 1�� ��ǻ�Ͱ� ����
	�ϰ� ���� �ʺ�켱Ž��(bfs)�� �����ϱ� �߳�
	*/
	int iSize{};
	int iLink{};
	CIN >> iSize >> iLink;
	int iInput[2];

	vector<bool> vecCheck(iSize);
	fill(vecCheck.begin(), vecCheck.end(), false);

	map<int, vector<int>> mapNet;
	for (int i = 0; i < iLink; ++i)
	{
		CIN >> iInput[0] >> iInput[1];
		mapNet[iInput[0]].push_back(iInput[1]);
		mapNet[iInput[1]].push_back(iInput[0]);
		cout << iInput[0] << '\t' << iInput[1] << endl;
	}

	queue<int> stlReserve;
	stlReserve.push(1);
	while (!stlReserve.empty())
	{
		for (auto i : mapNet[stlReserve.front()])
		{
			if (vecCheck[i - 1])
				continue;
			else
				stlReserve.push(i);
		}
		vector<int> src;
		mapNet[stlReserve.front()] = src;
		vecCheck[stlReserve.front() - 1] = true;
		stlReserve.pop();
	}

	
	int iResult{ 0 };
	for (bool Temp : vecCheck)
		iResult += (int)Temp;
	cout << iResult - 1; 
}