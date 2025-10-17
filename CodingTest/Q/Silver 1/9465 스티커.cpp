#include "pch.h"
#include "Header.h"
#include <vector>

enum WAY { UP, DOWN, NOT, WAY_END };
void Solve(ifstream* _pLoadStream)
{
	/*
	�ϳ� �����ϸ� ��ĭ �����¿쿡 �ִ°� ���� ���Ѵ�. ���� ���� �ڽ�Ʈ�� ���� ����ϱ�
	���Ұ� ���Ƽ� BFS/DFS���� Ž�� �˰����� �Ұ�����
	������ �ΰ� �߿� �ϳ� ���� or ���� �������� �����ϸ� �ǰڴ�.

	���α׷��� ��ȸ�� �ڵ� �׽�Ʈ����
	"�ִ�/�ּڰ�
	"�κ� ������ �ɰ� �� ����"
	"������ ������ ���� ��"
	�̷� �� ���̸� ������ DP �ǽ��� ���� �� ����.
	*/
	int CaseInput;
	int Size;
	int Input;
	CIN >> CaseInput;
	vector<int> Stickers[3];
	for (int Case = 0; Case < CaseInput; ++Case)
	{
		CIN >> Size;
		Stickers[UP].clear();
		Stickers[DOWN].clear();
		Stickers[NOT].clear();

		Stickers[UP].reserve(Size);
		Stickers[DOWN].reserve(Size);
		Stickers[NOT].resize(Size, 0);

		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Stickers[UP].push_back(Input);
		}
		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Stickers[DOWN].push_back(Input);
		}
		for (int i = 1; i < Size; ++i)
		{
			Stickers[UP][i] += max(Stickers[DOWN][i - 1], Stickers[2][i - 1]);
			Stickers[DOWN][i] += max(Stickers[UP][i - 1], Stickers[2][i - 1]);
			Stickers[NOT][i] += max(Stickers[UP][i - 1], Stickers[DOWN][i - 1]);
		}

		
		cout << max(Stickers[UP][Size - 1], Stickers[DOWN][Size - 1]) << '\n';
	}
}