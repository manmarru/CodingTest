#include "pch.h"
#include "Header.h"
#include <vector>

/*
��û�� ������ �ݽð�, �Ʒ����� �ð�� �ٶ��� ����.

������ ������ ������ �������� �ڽ��� ����/5 ��ŭ �� ĭ�� ������ �����ش�.
������ ���������� ���� �ְ� �޴´�.
*/

vector<vector<int>> Room;
vector<vector<int>> NextRoom;
int RoomSizeX, RoomSizeY;
void Spread(int _y, int _x)
{
	int Cnt{ 0 };
	if (_y > 0 && Room[_y - 1][_x] != -1)
	{
		NextRoom[_y - 1][_x] += Room[_y][_x] / 5;
		++Cnt;
	}
	if (_y < RoomSizeY - 1 && Room[_y + 1][_x] != -1)
	{
		NextRoom[_y + 1][_x] += Room[_y][_x] / 5;
		++Cnt;
	}
	if (_x > 0 && Room[_y][_x - 1] != -1)
	{
		NextRoom[_y][_x - 1] += Room[_y][_x] / 5;
		++Cnt;
	}
	if (_x < RoomSizeX - 1)
	{
		NextRoom[_y][_x + 1] += Room[_y][_x] / 5;
		++Cnt;
	}
	Room[_y][_x] -= (int)(Room[_y][_x] / 5) * Cnt;
}

void TurningAir(int _Upper)
{
	for (int y = _Upper - 1; y > 0; --y)
	{
		Room[y][0] = Room[y - 1][0];
	}

	for (int x = 0; x < RoomSizeX - 1; ++x)
	{
		Room[0][x] = Room[0][x + 1];
	}

	for (int y = 0; y < _Upper; ++y)
	{
		Room[y][RoomSizeX - 1] = Room[y + 1][RoomSizeX - 1];
	}

	for (int x = RoomSizeX - 1; x > 0; --x)
	{
		Room[_Upper][x] = Room[_Upper][x - 1];
	}

	//��û��κ�
	Room[_Upper][0] = -1;
	Room[_Upper][1] = 0;

	//�Ʒ���
	int Lower = _Upper + 1;

	for (int y = Lower; y < RoomSizeY - 1; ++y)
	{
		Room[y][0] = Room[y + 1][0];
	}

	for (int x = 0; x < RoomSizeX - 1; ++x)
	{
		Room[RoomSizeY - 1][x] = Room[RoomSizeY - 1][x + 1];
	}

	for (int y = RoomSizeY - 1; y > Lower; --y)
	{
		Room[y][RoomSizeX - 1] = Room[y - 1][RoomSizeX - 1];
	}
	
	for (int x = RoomSizeX - 1; x > 0; --x)
	{
		Room[Lower][x] = Room[Lower][x - 1];
	}

	Room[Lower][0] = -1;
	Room[Lower][1] = 0;

}

void Solve(ifstream* _pLoadStream)
{
	int TargetTime;
	CIN >> RoomSizeY >> RoomSizeX >> TargetTime;
	Room.resize(RoomSizeY, vector<int>(RoomSizeX));
	NextRoom.resize(RoomSizeY, vector<int>(RoomSizeX));
	int UpperCleaner{ -1 }, LowerCleaner{ -1 };

	for (int y = 0; y < RoomSizeY; ++y)
	{
		for (int x = 0; x < RoomSizeX; ++x)
		{
			CIN >> Room[y][x];
			if (Room[y][x] == -1)
			{
				if (UpperCleaner != -1)
					LowerCleaner = y;
				else
					UpperCleaner = y;
			}
		}
	}
	
	for (int i = 0; i < TargetTime; ++i)
	{
		for (int y = 0; y < RoomSizeY; ++y)
		{
			for (int x = 0; x < RoomSizeX; ++x)
			{
				if (Room[y][x] > 4)
				{
					Spread(y, x);
				}
			}
		}

		for (int y = 0; y < RoomSizeY; ++y)
		{
			for (int x = 0; x < RoomSizeX; ++x)
			{
				Room[y][x] += NextRoom[y][x];
				NextRoom[y][x] = 0;
			}
		}

		TurningAir(UpperCleaner);
	}

	int Result{ 0 };
	for (int y = 0; y < RoomSizeY; ++y)
	{
		for (int x = 0; x < RoomSizeX; ++x)
		{
			Result += Room[y][x];
		}
	}
	cout << Result + 2; // ��û�� -1 �ι� �������ϱ�
}