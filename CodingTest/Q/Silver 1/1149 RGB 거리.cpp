#include "pch.h"
#include "Header.h"
#include <vector>
#include <array>

enum COLOR { R, G, B, COLOR_END };

void Solve(ifstream* _pLoadStream)
{
	/*
	�� ���� ���� R G B �� ��ĥ���� ���� �ڽ�Ʈ�� ����
	���� ���ӵ��� �ʰ� ���� �� ������� ��� ���� ��ĥ�ϱ�

	DP���� �ϳ� ������ ��� ������ ����ó�� �ϴµ�
	*/
	vector<int> DP[COLOR_END];
	int Size;
	CIN >> Size;
	for (int i = 0; i < COLOR_END; ++i)
		DP[i].reserve(Size);
	for (int i = 0; i < Size; ++i)
	{
		DP[R].emplace_back();
		DP[G].emplace_back();
		DP[B].emplace_back();
		CIN >> DP[R][i] >> DP[G][i] >> DP[B][i];
	}

	for (int i = 1; i < Size; ++i)
	{
		DP[R][i] += min(DP[G][i - 1], DP[B][i - 1]);
		DP[G][i] += min(DP[R][i - 1], DP[B][i - 1]);
		DP[B][i] += min(DP[R][i - 1], DP[G][i - 1]);
	}
	cout << min(min(DP[R].back(), DP[G].back()), DP[B].back());
}