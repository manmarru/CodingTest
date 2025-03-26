#include "pch.h"
#include "Header.h"

class CMyNode
{
public:
	CMyNode(int _iNum, CMyNode* _pUnder) : m_iNum{ _iNum }, m_pUnder{ _pUnder }
	{
	}
public:
	int m_iNum;
	CMyNode* m_pUnder;
};

class CMyStack
{
public:
	void Push(int _iNum)
	{
		CMyNode* pNode = new CMyNode(_iNum, m_pTop);
		m_pTop = pNode;
		++iSize;
	}
	int Pop()
	{
		if (nullptr == m_pTop)
			return -1;

		CMyNode* pNode = m_pTop;
		int iResult = pNode->m_iNum;
		m_pTop = pNode->m_pUnder;

		delete(pNode);
		pNode = nullptr;
		--iSize;

		return iResult;
	}
	int size()
	{
		return iSize;
	}
	bool empty()
	{
		return nullptr == m_pTop;
	}
	int top()
	{
		return m_pTop == nullptr ? -1 : m_pTop->m_iNum;
	}
private:
	CMyNode* m_pTop{ nullptr };
	int iSize{};
};

void Solve(ifstream* _pLoadStream)
{
	/*
	스텍 구현
	push
	pop
	size
	empty
	top
	*/
	
	int iInput{};
	CIN >> iInput;
	string szInput;
	int iNum;
	CMyStack myStack;

	for (int i = 0; i < iInput; ++i)
	{
		CIN >> szInput;
		if ("push" == szInput)
		{
			CIN >> iNum;
			myStack.Push(iNum);
		}
		else if ("pop" == szInput)
		{
			cout << myStack.Pop() << '\n';
		}
		else if ("size" == szInput)
		{
			cout << myStack.size() << '\n';
		}
		else if ("empty" == szInput)
		{
			cout << myStack.empty() << '\n';
		}
		else if ("top" == szInput)
		{
			cout << myStack.top() << '\n';
		}
	}
	
}