#include "pch.h"
#include "Header.h"
#include <vector>

/*
https://www.acmicpc.net/problem/9934
딱봐도 인덱싱으로 풀 수 있는 문제였고

좀 복잡하게 본다면 DFS로 트리 타고 들어가면서 출력하는 방법이 있겠다.
이걸 편하게 풀고 싶으면
레벨별로 배열을 따로 만들고
DFS타고 들어갈 때 ++레벨 을 계속 전달해줘서 현재 어느 레벨인지 저장하면 되겠다.
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