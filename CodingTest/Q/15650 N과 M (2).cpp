#include "pch.h"
#include "Header.h"
#include <vector>

vector<int> Nums;
vector<bool> Picked;
int MaxNum;
int Pick;

//7�� 3���̶�� �����غ���
//�ε����� 0���� �����Ѵ�.
void dfs(int _Num, int _Index)
{
	Picked[_Num] = true;
	if (_Index == Pick - 1)
	{
		for (int i = 1; i <= MaxNum; i++)
		{
			if (Picked[i])
				cout << i << ' ';
		}
		cout << '\n';
	}
	else
	{
		for (int i = _Num + 1; i <= MaxNum - Pick + _Index + 2; ++i)
		{
			if (Picked[_Num + 1])
				continue;
			dfs(i, _Index + 1);
			Picked[i] = false;
		}
	}

}

void Solve(ifstream* _pLoadStream)
{
	/* 
	1���� N������ �ڿ��� ��
	�ߺ� ���� M���� �� ������
	������������ ��� ����ϱ�

	���ʿ��� �κ��� Ž������ �ʰ� �������� ���ư��� �� ��Ʈ��ŷ�̶�� ��
	���⼭�� ���� �ε������� ���� ���ڸ� �湮���� �ʴ� �Ͱ�
	���� �ε����� ���ư��� +1 �� ���ִ� �� �ش��ϰ���?

	<algorithm> �� prev_permutation ��°� �ִ�.
	�̰� ���� ���� ����(�迭 or �����̳�)�� ���� ũ���� ������ ������ش�.
	*/

	CIN >> MaxNum >> Pick;
	Pick += 1;
	Nums.resize(MaxNum + 1, 0);
	Picked.resize(MaxNum + 1, false);
	dfs(0, 0);
}