#include "pch.h"
#include "Header.h"
#include <vector>
#include <limits.h>

/*
ù ���� ������ ���� ���� �ٸ���.
���� ���� ���� �����ؼ� ������ �ʴ´�.

�� ���� �� ������ ĥ�ϴ� ����� �־�����
���� ���� �ڽ�Ʈ�� ���� ��� ĥ�ϴ� ������ ����ϱ�
*/

struct RGB
{
	int R = 0;
	int G = 0;
	int B = 0;
};

void Solve(ifstream* _pLoadStream)
{
	int HouseSize;
	CIN >> HouseSize;
	vector<RGB> Cost(HouseSize);
	vector<RGB> DP(HouseSize);
	for (int i = 0; i < HouseSize; ++i)
	{
		CIN >> Cost[i].R >> Cost[i].G >> Cost[i].B;
	}
	int Result{ INT_MAX };
	
	//�̰� �ݺ������� ���̸� �ڵ� ���̰� ���丷���ٵ�...
	DP[0] = { INT_MAX, Cost[0].G, Cost[0].B };// �������� R ����
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].R + min(DP[HouseSize - 2].G, DP[HouseSize - 2].B));

	DP[0] = { Cost[0].R, INT_MAX, Cost[0].B }; //�������� G ����
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].G + min(DP[HouseSize - 2].R, DP[HouseSize - 2].B));

	DP[0] = { Cost[0].R, Cost[0].G, INT_MAX }; //�������� B ����
	for (int i = 1; i < HouseSize; ++i)
	{
		DP[i].R = min(DP[i - 1].G, DP[i - 1].B) + Cost[i].R;
		DP[i].G = min(DP[i - 1].R, DP[i - 1].B) + Cost[i].G;
		DP[i].B = min(DP[i - 1].R, DP[i - 1].G) + Cost[i].B;
	}
	Result = min(Result, Cost[HouseSize - 1].B + min(DP[HouseSize - 2].R, DP[HouseSize - 2].G));

	cout << Result;
}