#include "pch.h"
#include "Header.h"
#include <vector>

struct LINK
{
	int start;
	int end;
};

/*
Links�� �������� �ʰ� �Է¹����鼭 �ٷ� ó������ ���� �κ��� �� �ƽ���.��
*/

void Solve(ifstream* _pLoadStream)
{
	int VertexSize;
	int LinkSize;
	CIN >> VertexSize >> LinkSize;
	vector<LINK> Links(LinkSize);
	vector<int> Vertices(VertexSize); // ���Ͽ� ��Ʈ�� ����Ŵ

	for (int i = 0; i < LinkSize; ++i)
	{
		CIN >> Links[i].start >> Links[i].end;
	}

	for (int i = 0; i < VertexSize; ++i)
	{
		Vertices[i] = i;
	}

	int End, Next;
	int StartRoot, EndRoot;
	for (int i = 0; i < LinkSize; ++i)
	{
		StartRoot = Links[i].start;
		End = EndRoot = Links[i].end;

		while (Vertices[StartRoot] != StartRoot)
		{
			StartRoot = Vertices[StartRoot];
		}

		while (Vertices[EndRoot] != EndRoot)
		{
			EndRoot = Vertices[EndRoot];
		}
		
		if (StartRoot == EndRoot)
		{
			cout << i + 1;
			return;
		}

		
		while (End != EndRoot)
		{
			Next = Vertices[End];
			Vertices[End] = StartRoot;
			End = Next;
		}
		Vertices[EndRoot] = StartRoot;
		
	}

	cout << 0;
}