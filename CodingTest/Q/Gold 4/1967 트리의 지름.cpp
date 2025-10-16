#include "pch.h"
#include "Header.h"
#include <vector>
#include <climits>

struct NODE
{
	vector<NODE*> Children; // 코스트, 인덱스
	// 참고로 이진트리라고 한 적 없다.
	int Cost = 0; // 마지막 인덱스에 받고 세개 정렬하면 앞에 두개가 가장큰거임
};

int answer{ 0 };
int DP(NODE* _Curr)
{
	//보유한 경로들 중 가장 긴 경로를 반환
	//경로들 중 가장 긴 두개를 합했을 때 answer 보다 크다면 answer 갱신
	//잎사귀 노드까지 내려갔다면 부모에서 자기로 오는데 드는 비용 반환
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
	트리를 아무데나 잡고 쭉 잡아늘였을 때 가장  길게 나오는 길이 출력하기
	1번 노드가 루트노드임
	플루이드 못쓴다.
	노드가 10000개까지 나오는데 그러면 100000000 개의 계산값을 저장해야된다.
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
	// 모든 노드의 자식이 하나인 트리면 DP 루프 내부에서 answer가 갱신이 안되니까
	// 반환값까지 받아봐야 한다.
	cout << answer;
}