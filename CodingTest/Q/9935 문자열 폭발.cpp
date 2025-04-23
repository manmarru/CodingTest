#include "pch.h"
#include "Header.h"
#include <list>
#include <string>

void Solve(ifstream* _pLoadStream)
{
	/*
	��ȣ �����ϴ°�ó�� �ܾ�� ��ź �ܾ ����� �� ������� �� ��ź �ܾ ����� �ݺ��ϴ°�
	�ܾ �������� �ʴٸ� FRULA ���

	������ ��ȸ�� �ȵǴϱ� list�� ���.
	���� ���Ÿ� �ϳ��� ������ �ٽ� �ְ� �ؾߵǴϱ� �� �ǰ��غ�����.

	���ڸ� �ϳ��� ��ȸ�ϸ鼭 ����Ʈ�� �ְ�, ���� ���� ��ź�� ������ ���ڸ�
	���� ���� �Ųٷ� ��ȸ��
	*/
	string Letter;
	string Boom;
	CIN >> Letter >> Boom;
	char Last = Boom.back();
	int Cnt(0);

	string Curr;
	for (char Temp : Letter)
	{
		Curr.push_back(Temp);
		if (Temp == Last)
		{
			auto iter = --Curr.end();
			do
			{
				if (*iter == Boom[(int)Boom.size() - Cnt - 1])
				{
					++Cnt;
					if (Cnt == (int)Boom.size())
					{
						for (int i = 0; i < Cnt; ++i)
							Curr.pop_back();
						Cnt = 0;
						break;
					}
				}
				else
				{
					Cnt = 0;
					break;
				}
			} while (iter-- != Curr.begin());
		}
		else
			Cnt = 0;
	}
	
	if (Curr.empty())
		cout << "FRULA";
	else
	{
		for (char& Temp : Curr)
			cout << Temp;
	}
}