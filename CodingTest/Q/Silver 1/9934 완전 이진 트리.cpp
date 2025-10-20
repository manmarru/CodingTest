#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/9934
������ �ε������� Ǯ �� �ִ� ��������

�� �����ϰ� ���ٸ� DFS�� Ʈ�� Ÿ�� ���鼭 ����ϴ� ����� �ְڴ�.
�̰� ���ϰ� Ǯ�� ������
�������� �迭�� ���� �����
DFSŸ�� �� �� ++���� �� ��� �������༭ ���� ��� �������� �����ϸ� �ǰڴ�.
*/

void Solve(ifstream* _pLoadStream)
{
	int Level;
	CIN >> Level;

	vector<int> Nodes;
	int Size;

	Size = pow(2, Level) - 1;
	Nodes.resize(Size);
	for (int i = 0; i < Size; ++i)
	{
		CIN >> Nodes[i];
	}

	for (int i = Level; i >= 1; --i)
	{
		int D = pow(2, i);
		int Curr = pow(2, i - 1);

		while (Curr <= Size)
		{
			cout << Nodes[Curr - 1] << ' ';
			Curr += D;
		}
		cout << endl;
	}
}