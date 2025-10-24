#include "pch.h"
#include "Header.h"

#include <unordered_map>

#define MAXCOST 100000000
/*
�߾ӿ��� ������ �ڽ�Ʈ 2(��ǻ� ó����)
�����̵� �ڽ�Ʈ 3
�ݴ��� �̵� �ڽ�Ʈ 4
���Ϲ��� ��� �ڽ�Ʈ 1
�׸����⿣ �� ��ġ�� ���� �ൿ�� ������ �ִ°� dp������?

�ٸ� ����� Ǯ�� ���� Before After�� ���ϰ� ������ �� �� ����Ѵ�.
�̰� �� ������ �ѵ� �޸� ���̰� �׸�ŭ ���� ����. (5�� ����)
*/
enum WAY { MID = 0b00001, UP = 0b00010, LEFT = 0b00100, DOWN = 0b01000, RIGHT = 0b10000, WAY_END = 5 };// ������ �Է°��̶� �����ϴ�.
const int Way[WAY_END] { MID, UP, LEFT, DOWN, RIGHT };
//						  1   2    4      8      16
void Solve(ifstream* _pLoadStream)
{
	int Input;
	unordered_map<int, int> Before;
	unordered_map<int, int> After;
	unordered_map<int, int> ForCopy;

	ForCopy[MID | UP] = MAXCOST; //3
	ForCopy[MID | LEFT] = MAXCOST; //5
	ForCopy[MID | DOWN] = MAXCOST; //9
	ForCopy[MID | RIGHT] = MAXCOST; //17
	ForCopy[UP | LEFT] = MAXCOST; //6
	ForCopy[UP | DOWN] = MAXCOST; //10
	ForCopy[UP | RIGHT] = MAXCOST; //18
	ForCopy[LEFT | DOWN] = MAXCOST; //12
	ForCopy[LEFT | RIGHT] = MAXCOST; //20
	ForCopy[DOWN | RIGHT] = MAXCOST; //24
	Before = After = ForCopy;

	CIN >> Input;
	After[Way[Input] | MID] = 2;

	for (auto Temp : After)
		cout << Temp.first << " : " << Temp.second << '\n';
	cout << ���� << endl;


	int Record;
	while (1)
	{
		CIN >> Input;
		if (Input == 0)
			break;

		swap(Before, After);
		After = ForCopy;
		for (auto& Curr : Before)
		{
			if (Curr.second == MAXCOST) // ���� DP����� ������
				continue;

			if ((Curr.first & Way[Input]) != 0) // �̹� ���������
			{
				After[Curr.first] = min(After[Curr.first], Curr.second + 1);
				continue;
			}

			//for (const int i : Way)
			for(int i = 0; i < 5; ++i)
			{
				if ((Curr.first & (int)pow(2,i)) == 0)
					continue;
				
				Record = (Curr.first ^ (int)pow(2, i)) | Way[Input]; // �� ���� ������ư ���

				if ((int)pow(2,i) == MID)
					After[Record] = min(After[Record], Curr.second + 2);
				else if (((Input + i) % 2) == 0) // �ݴ��� ���� �������
					After[Record] = min(After[Record], Curr.second + 4);
				else
					After[Record] = min(After[Record], Curr.second + 3);
			}
		}
		for (auto Temp : After)
			cout << Temp.first << " : " << Temp.second << '\n';
		cout << ���� << endl;
	}

	int Result{ MAXCOST };
	for (auto Temp : After)
		Result = min(Result, Temp.second);
	cout << Result;
}