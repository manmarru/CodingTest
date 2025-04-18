#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

struct OBJ
{
	vector<int> Entry;
	bool Truth = false;
};


void Solve(ifstream* _pLoadStream)
{
	/*
	��Ƽ���� �������� �� �ǵ�
	������ �ƴ� ����� ��Ƽ�� ���� ������ ������ ���ؾ� �Ѵ�.
	�� ����� ���ǰ� ������ �� �� ������ �ȵȴ�.
	�������� �� �� �ִ� �ִ� ��Ƽ ���� ���ϱ�
	
	�ϴ� ������ ���ؾ� �ϴ� ��Ƽ�� �����ϰ�
	�� ��Ƽ�� ���� ������ ����� ��� ������ �ƴ� ������� ����
	��� ��ȣ�� [1, 50] �̱� ������ ����ִ� 0�� �ε����� �־���.

	1. ������ �ƴ� ������� ���θ� ����
	2. ������ ���ؾ� �ϴ� ��Ƽ���� ���θ� ����
	3. ��Ƽ�� �����ϴ� ����� ����
	4. �����ں� �����ϴ� ��Ƽ�� ����
	4. ������ ���ؾ� �ϴ� ��Ƽ�� ���� Destination�� ����
	Destination.front ���� ��Ƽ�� ��ȸ
	5. �����ڸ� ��ȸ�ϸ鼭 �� ����� true�� ����
	6. �ش� ��Ƽ�� �����ڵ��� �����ϴ� �ٸ� ��Ƽ���� Destination �� �ְ� �ݺ�
	7. ���� ���

	����� Union find �� ����ϴ� �����, ����鰣�� ���� �׷����� ���� Ž���ϴ� ����� �ִ�.
	*/

	// ����� �� n �� ��Ƽ�� �� m
	// ������ �ƴ� ��� ��ȭ ��ȣ
	// �� ��Ƽ���� ������ �ƴ� ��� ���� ����� �ε��� �־���
	int Mansize, Partysize, TrueMansize;
	int Input;
	CIN >> Mansize >> Partysize;
	vector<OBJ> People(Mansize + 1); // 0�� ����� ���°���
	vector<OBJ> Parties(Partysize);
	CIN >> TrueMansize;
	for (int i = 0; i < TrueMansize; ++i)
	{
		CIN >> Input;
		People[Input].Truth = true;
	}
	
	int Size;
	for (int party = 0; party < Partysize; ++party)
	{
		CIN >> Size;
		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Parties[party].Entry.push_back(Input);
			People[Input].Entry.push_back(party);
			if (People[Input].Truth)
			{
				Parties[party].Truth = true;
				for (int Temp : Parties[party].Entry)
					People[Temp].Truth = true;
			}
		}
	}

	queue<int> Destination; // ��Ƽ��ȣ
	for(int i = 0; i < Partysize; ++i)
	{
		if (Parties[i].Truth)
			Destination.push(i);
	}

	int Curr;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();

		for (int i : Parties[Curr].Entry)
		{
			for (int Temp : People[i].Entry)
			{
				if (!Parties[Temp].Truth)
				{
					Destination.push(Temp);
					Parties[Temp].Truth = true;
				}
			}
		}
	}

	int Result(0);
	for (int i = 0; i < Partysize; ++i)
	{
		if (Parties[i].Truth)
			++Result;
	}
	cout << Partysize - Result;
}