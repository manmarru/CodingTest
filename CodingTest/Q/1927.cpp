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
	�ּ� �� ����
	1. �迭�� �ڿ���x�� �ִ´�.
	2. �迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.

	�ù� �ּ��� ���� �����ϴٰ� �Ƕ˽ΰ� �켱���� ť ���� �Ἥ ������.
	�����Ѱ� MinHip.h ����
	�ּ����� ������ĺ��� �迭���� + �ε��������� �ξ� ����
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