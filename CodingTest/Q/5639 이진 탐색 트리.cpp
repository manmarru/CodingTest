#include "pch.h"
#include "Header.h"

struct NODE
{
	int Data;
	NODE* Left = nullptr;
	NODE* Right = nullptr;
	void insert(int data)
	{
		if (Data > data)
		{
			if (Left == nullptr)
			{
				Left = new NODE;
				Left->Data = data;
				return;
			}
			else
				Left->insert(data);
		}
		else if (Data < data)
		{
			if (Right == nullptr)
			{
				Right = new NODE;
				Right->Data = data;
				return;
			}
			else
				Right->insert(data);
		}
	}
};

void LRC(NODE* SubRoot)
{
	if (nullptr != SubRoot->Left)
		LRC(SubRoot->Left);
	if (nullptr != SubRoot->Right)
		LRC(SubRoot->Right);
	cout << SubRoot->Data << '\n';
}

void Solve(ifstream* _pLoadStream)
{
	/*
	전위 탐색 결과로 출력되는 원소들을 후위 탐색으로 바꿔서 출력하기
	그냥 트리 만든 다음에 후위출력해서 풀리긴 했지만 다른 방법이 있긴 한가보다.

	<다른방법>
	첫 원소 = Root
	첫 원소보다 작은 원소들은 Left, 큰 원소들은 Right
	첫 원소 빼고 재귀해서 그 첫 원소를 Root로 하고 다시 Left Right 구분
	원소가 하나만 남을 때까지 재귀하는거야
	그다음 구분된걸로 후위출력
	*/
	int Input;
	CIN >> Input;
	NODE* Root = new NODE;
	Root->Data = Input;
	int before(Input);
	
	while (CIN >> Input)
	{
		Root->insert(Input);
	}
	LRC(Root);
}