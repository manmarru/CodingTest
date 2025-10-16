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
	���� Ž�� ����� ��µǴ� ���ҵ��� ���� Ž������ �ٲ㼭 ����ϱ�
	�׳� Ʈ�� ���� ������ ��������ؼ� Ǯ���� ������ �ٸ� ����� �ֱ� �Ѱ�����.

	<�ٸ����>
	ù ���� = Root
	ù ���Һ��� ���� ���ҵ��� Left, ū ���ҵ��� Right
	ù ���� ���� ����ؼ� �� ù ���Ҹ� Root�� �ϰ� �ٽ� Left Right ����
	���Ұ� �ϳ��� ���� ������ ����ϴ°ž�
	�״��� ���еȰɷ� �������
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