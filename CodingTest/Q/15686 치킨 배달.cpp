#include "pch.h"
#include "Header.h"
#include <vector>

struct OBJ
{
	int y, x;
};

vector<OBJ> Houses;
vector<OBJ> Stores;

vector<bool> Picked;
int Result(99999);
int StoreSize;

void DFS(int Before, int More) // ���� �������� Before�ε����� ����� More ��ŭ �� ���� ����
{
	if (0 == More)
	{
		// ��� �� result ����
		int Sum(0);
		int Less;
		for (OBJ House : Houses)
		{
			Less = 99999;
			for (int i = 0; i < StoreSize; ++i)
			{
				if (Picked[i])
				{
					Less = min(Less, abs(House.x - Stores[i].x) + abs(House.y - Stores[i].y));
				}
			}
			Sum += Less;
		}

		Result = min(Result, Sum);
		cout << Sum << endl;
		return;
	}
	
	for (int i = Before + 1; i < StoreSize; ++i)
	{
		if (!Picked[i])
		{
			Picked[i] = true;
			DFS(i, More - 1);
			Picked[i] = false;
		}
	}

	return;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	y,x �� ġŲ���Կ� ���� ��ǥ�� �־��� (1 <= y, x)

	ġŲ���� ���� �Ÿ��� Dy + Dx �̴�.

	ġŲ���� �� �ִ� M���� �����ؼ� ġŲ������ �Ÿ��� ���� �ּҰ� �ǰ� �ؾ� ��.

	�Ÿ� ������� �ϳ��� �����°� �ǹ̰� �����Ű�����? �� ��� ���� �� �غ��� �˵�?

	m���� �������� �� ġŲ����Ʈ ������ ���� ����غ��°� ������
	*/

	int Size, Pick;

	CIN >> Size >> Pick;
	int Input;
	for (int y = 0; y < Size; ++y)
	{
		for (int x = 0; x < Size; ++x)
		{
			CIN >> Input;

			if (Input == 1)
			{
				Houses.push_back({ y, x });
			}
			else if (Input == 2)
			{
				Stores.push_back({ y, x });
			}
		}
	}
	Picked.resize(Stores.size(), false);
	StoreSize = Stores.size();
	// �Է��� ���� ����, Houses�� Stores �� �� ä�����.

	DFS(-1, Pick); // -1�� �����߰�(�ϰ͵� ���� �Ȱ�����ϱ�) Pick�� �� ���� ����
	cout << Result << endl;
}