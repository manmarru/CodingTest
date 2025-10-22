#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/1285
���� Ǯ� �Ǳ� �ϴµ� ��Ʈ����ŷ ���� Ǯ�̰� �ְŵ�? �ٵ� ������� ���� �𸣰���
https://www.acmicpc.net/source/99166793
�̻���� ������ 10�� ������ Ǯ���µ� ���Ѱ����� �𸣰���
*/
enum COIN {T, H}; // H�� �ո�

int Size;
vector<vector<COIN>> Board;
vector<char> Reverse;
int Result{ 100000000 };

int Count()
{
	int Result{ 0 };
	int Temp;
	for(int y = 0; y < Size; ++y)
	{
		Temp = 0;
		for (int x = 0; x < Size; ++x)
		{
			Temp += Board[y][x] ^ Reverse[x];
		}
		Result += min(Temp, Size - Temp);
	}

	return Result;
}

void DFS(int CurIndex)
{
	Result = min(Result, Count());

	for (; CurIndex < Size; ++CurIndex)
	{
		Reverse[CurIndex] = true;
		DFS(CurIndex + 1);
		Reverse[CurIndex] = false;
	}
}

void Solve(ifstream* _pLoadStream)
{
	CIN >> Size;
	Board.resize(Size, vector<COIN>(Size));
	Reverse.resize(Size, false);

	char Input;
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input;
			Board[y][x] = Input == 'H' ? H : T;
		}
	}

	DFS(0);
	cout << Result;
}


/*


#define M 22
int n, d[M][M], arr[M];
int res = 400, cnt, sum;
string s;

int Temp()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < n; j++) 
			if (s[j] == 'T')
				d[i][j] = 1;
	}

	for (int i = 0; i < (1 << n); i++) 
	{
		for (int j = 0; j < n; j++) 
			arr[j] = i & (1 << j) ? 1 : 0;

		sum = 0;
		for (int j = 0; j < n; j++) 
		{
			cnt = 0;
			for (int k = 0; k < n; k++)
				cnt += arr[k] ? 1 - d[k][j] : d[k][j];
			sum += min(cnt, n - cnt);
		}
		res = min(res, sum);
	}
	cout << res;
	return 0;
}

*/