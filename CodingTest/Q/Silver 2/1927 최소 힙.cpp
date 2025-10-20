#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>


class CHip
{
public:
	void push(int _iInput)
	{
		m_contain.push(_iInput);
	}
	int pop()
	{
		if (m_contain.empty())
			return 0;
		int iResult{m_contain.top()};
		m_contain.pop();

		return iResult;
	}

private:
	priority_queue<int, vector<int>, greater<int>> m_contain;
};

void Solve(ifstream* _pLoadStream)
{
	/*
	최소 힙 구현
	1. 배열에 자연수x를 넣는다.
	2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.

	시발 최소힙 직접 구현하다가 피똥싸고 우선순위 큐 대충 써서 구현함.
	구현한건 MinHip.h 참고
	최소힙은 노드형식보다 배열형식 + 인덱스접근이 훨씬 좋음
	*/
	int iSize;
	int iInput;
	CIN >> iSize;
	CHip myHip;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> iInput;
		if (0 == iInput)
			cout << myHip.pop() << '\n';
		else
			myHip.push(iInput);
	}

}