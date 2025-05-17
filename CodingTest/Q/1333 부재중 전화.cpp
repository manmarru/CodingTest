#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>


void Solve(ifstream* _pLoadStream)
{
	/*
	�� ���̰� Length�� �뷡�� Size ���� ��´�. �� �뷡 ���̿��� 5���� ������ �ִ�.
	���ÿ� ���Ҹ��� Gap�� ���� 1�ʾ� �︰��.
	���ʷ� �����ð��� ���Ҹ��� �︮�� �ð��� ���ϱ�(������ �뷡�� �� ���� ��)

	��������� �ڲ� Ʋ���� ��û ����ߴ�.
	�������� ���� �õ��� ��������
	�̷��Ÿ� ���� bool �迭���ٰ� �� �� ��Ȳ�� �־ üũ�ϴ°� �� ��������?
	*/
	int Size;
	int Length;
	int Gap;

	CIN >> Size >> Length >> Gap;

	int Curr{ 0 };

	int RemainGap;
	for (int i = 0; i < Size; ++i)
	{
		Curr += Length;
		if (Curr % Gap == 0)
		{
			cout << Curr;
			return;
		}
		RemainGap = Gap - Curr % Gap;
		if (RemainGap < 5)
		{
			cout << Curr + RemainGap;
			return;
		}

		Curr += 5;
	}
	Curr -= 5;
	cout << Curr + RemainGap;
}