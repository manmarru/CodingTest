#include "pch.h"
#include "Header.h"
#include <vector>
#include <climits>

struct NODE
{
	vector<NODE*> Children; // �ڽ�Ʈ, �ε���
	// ����� ����Ʈ����� �� �� ����.
	int Cost = 0; // ������ �ε����� �ް� ���� �����ϸ� �տ� �ΰ��� ����ū����
};

int answer{ 0 };
int DP(NODE* _Curr)
{
	//������ ��ε� �� ���� �� ��θ� ��ȯ
	//��ε� �� ���� �� �ΰ��� ������ �� answer ���� ũ�ٸ� answer ����
	//�ٻ�� ������ �������ٸ� �θ𿡼� �ڱ�� ���µ� ��� ��� ��ȯ
	int result[3] = { -INT_MAX, -INT_MAX, -INT_MAX };

	for (NODE* Children : _Curr->Children)
	{
		result[2] = DP(Children);
		if (result[2] > result[1])
		{
			swap(result[2], result[1]);
			if (result[1] > result[0])
				swap(result[1], result[0]);
		}
	}

	if (_Curr->Children.empty())
		return _Curr->Cost;

	if (result[0] + result[1] > answer)
	{
		answer = result[0] + result[1];
	}

	return result[0] + _Curr->Cost;
}

void Solve(ifstream* _pLoadStream)
{
	/*
	Ʈ���� �ƹ����� ��� �� ��ƴÿ��� �� ����  ��� ������ ���� ����ϱ�
	1�� ��尡 ��Ʈ�����
	�÷��̵� ������.
	��尡 10000������ �����µ� �׷��� 100000000 ���� ��갪�� �����ؾߵȴ�.
	*/

	int NodeSize;
	CIN >> NodeSize;

	vector<NODE> Nodes(NodeSize + 1);

	int S, E, C;
	for (int i = 0; i < NodeSize - 1; ++i)
	{
		CIN >> S >> E >> C;
		Nodes[S].Children.push_back(&Nodes[E]);
		Nodes[E].Cost = C;
	}

	answer = max(answer, DP(&Nodes[1]));
	// ��� ����� �ڽ��� �ϳ��� Ʈ���� DP ���� ���ο��� answer�� ������ �ȵǴϱ�
	// ��ȯ������ �޾ƺ��� �Ѵ�.
	cout << answer;
}