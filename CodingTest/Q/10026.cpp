#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>
#define �Ѱ� continue
#define ���� push
#define �� true
#define ���� false

pair<int, int> operator+(pair<int, int> &Temp, pair<int, int> &Src)
{
	return { Temp.first + Src.first, Temp.second + Src.second };
}

void Solve(ifstream* _pLoadStream)
{
	/*
	RGB�� �̷���� �׸��ǿ��� ���� �� ������ ���� ã��
	��, ���Ϳ� �׸����� R == G
	������ �ѱ��ڵ�
	*/
	int �Է�ũ��;
	int ���[2]{ 0, 0 };
	CIN >> �Է�ũ��;

	vector<vector<char>> �׸���(�Է�ũ��);
	vector<vector<char>> ���ͱ׸���(�Է�ũ��);
	vector<vector<bool>> �湮���[2];
	queue<pair<int, int>> �湮����;
	�湮���[0].resize(�Է�ũ��);
	�湮���[1].resize(�Է�ũ��);
	for (int �� = 0; �� < �Է�ũ��; ��++)
	{
		�׸���[��].resize(�Է�ũ��);
		���ͱ׸���[��].resize(�Է�ũ��);
		�湮���[0][��].resize(�Է�ũ��);
		�湮���[1][��].resize(�Է�ũ��);
		fill(�湮���[0][��].begin(), �湮���[0][��].end(), false);
		fill(�湮���[1][��].begin(), �湮���[1][��].end(), false);
		for (int �� = 0; �� < �Է�ũ��; ��++)
		{
			CIN >> �׸���[��][��];
			���ͱ׸���[��][��] = �׸���[��][��] == 'R' ? 'G' : �׸���[��][��];
		}
	}

	pair<int, int> ������ġ, ������ġ;
	pair<int, int> ����[4]{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	for (int y = 0; y < �Է�ũ��; ++y)
	{
		for (int x = 0; x < �Է�ũ��; x++)
		{
			if (�湮���[0][y][x])
				�Ѱ�;
			�湮����.����({ y,x });
			�湮���[0][y][x] = ��;
			++���[0];
			while (!�湮����.empty())
			{
				������ġ = �湮����.front();
				�湮����.pop();
				for (int �� = 0; �� < 4; ��++)
				{
					������ġ = ������ġ + ����[��];
					if (������ġ.first < 0 || ������ġ.first >= �Է�ũ��
						|| ������ġ.second < 0 || ������ġ.second >= �Է�ũ��)
						�Ѱ�;
					if (�湮���[0][������ġ.first][������ġ.second])
						�Ѱ�;
					if (�׸���[������ġ.first][������ġ.second] != �׸���[������ġ.first][������ġ.second])
						�Ѱ�;
					�湮���[0][������ġ.first][������ġ.second] = ��;
					�湮����.����({������ġ.first, ������ġ.second});
				}
			}
		}
	}

	for (int y = 0; y < �Է�ũ��; ++y)
	{
		for (int x = 0; x < �Է�ũ��; x++)
		{
			if (�湮���[1][y][x])
				�Ѱ�;
			�湮����.����({ y,x });
			�湮���[1][y][x] = ��;
			++���[1];
			while (!�湮����.empty())
			{
				������ġ = �湮����.front();
				�湮����.pop();
				for (int �� = 0; �� < 4; ��++)
				{
					������ġ = ������ġ + ����[��];
					if (������ġ.first < 0 || ������ġ.first >= �Է�ũ��
						|| ������ġ.second < 0 || ������ġ.second >= �Է�ũ��)
						�Ѱ�;
					if (�湮���[1][������ġ.first][������ġ.second])
						�Ѱ�;

					if (���ͱ׸���[������ġ.first][������ġ.second] != ���ͱ׸���[������ġ.first][������ġ.second])
						�Ѱ�;

					�湮���[1][������ġ.first][������ġ.second] = ��;
					�湮����.����({ ������ġ.first, ������ġ.second });
				}
			}
		}
	}

	cout << ���[0] << ' ' << ���[1];
}