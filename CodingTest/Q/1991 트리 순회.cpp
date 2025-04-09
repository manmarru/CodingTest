#include "pch.h"
#include "Header.h"
#include <vector>

struct NODE
{
	char Name[2];
	char Left;
	char Right;
};

vector<NODE> Nodes;

void Preorder(NODE& _Curr) //CLR
{
	cout << _Curr.Name;
	if(_Curr.Left != '.')
		Preorder(Nodes[_Curr.Left - 'A']);
	if(_Curr.Right != '.')
		Preorder(Nodes[_Curr.Right - 'A']);
}

void Inorder(NODE& _Curr) //LCR
{
	if (_Curr.Left != '.')
		Inorder(Nodes[_Curr.Left - 'A']);
	cout << _Curr.Name;
	if (_Curr.Right != '.')
		Inorder(Nodes[_Curr.Right - 'A']);
}

void Postorder(NODE& _Curr) //LRC
{
	if (_Curr.Left != '.')
		Postorder(Nodes[_Curr.Left - 'A']);
	if (_Curr.Right != '.')
		Postorder(Nodes[_Curr.Right - 'A']);
	cout << _Curr.Name;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	전위, 중위, 후위 순회 구현하기
	*/

	int Size;
	CIN >> Size;
	Nodes.resize(Size);
	char InputName;

	for (int i = 0; i < Size; ++i)
	{
		CIN >> InputName;
		NODE& Curr = Nodes[InputName - 'A'];
		CIN >> Curr.Left >> Curr.Right;
		Curr.Name[0] = InputName;
	}

	Preorder(Nodes[0]);
	cout << '\n';
	Inorder(Nodes[0]);
	cout << '\n';
	Postorder(Nodes[0]);


}