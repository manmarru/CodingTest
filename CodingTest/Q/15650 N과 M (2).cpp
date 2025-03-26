#include "pch.h"
#include "Header.h"
#include <vector>

vector<int> Nums;
vector<bool> Picked;
int MaxNum;
int Pick;

//7개 3픽이라고 생각해보자
//인덱스는 0에서 시작한다.
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
	1부터 N까지의 자연수 중
	중복 없이 M개를 고른 수열을
	오름차순으로 모두 출력하기

	불필요한 부분은 탐색하지 않고 이전으로 돌아가는 걸 백트래킹이라고 해
	여기서는 앞의 인덱스보다 작은 숫자를 방문하지 않는 것과
	앞의 인덱스로 돌아가서 +1 을 해주는 게 해당하겠지?

	<algorithm> 에 prev_permutation 라는게 있다.
	이걸 쓰면 현재 순열(배열 or 컨테이너)을 다음 크기의 순열로 만들어준다.
	*/

	CIN >> MaxNum >> Pick;
	Pick += 1;
	Nums.resize(MaxNum + 1, 0);
	Picked.resize(MaxNum + 1, false);
	dfs(0, 0);
}