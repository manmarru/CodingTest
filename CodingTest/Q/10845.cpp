#include "pch.h"
#include "Header.h"
#include <string>

typedef struct tMyNode
{
	int m_iNum;
	tMyNode* m_pNext = nullptr;
}NODE;

class CMyQueue
{
public:
	void push(int _iNum)
	{
		NODE* Temp = new NODE{ _iNum, nullptr };
		if (0 == m_iSize)
		{
			m_pFront = Temp;
			m_pBack = Temp;
		}
		else
		{
			m_pBack->m_pNext = Temp;
			m_pBack = Temp;
		}
		++m_iSize;
	}
	int pop() 
	{
		if (0 == m_iSize)
			return -1;
		NODE* Temp = m_pFront;

		int iResult{ Temp->m_iNum };
		m_pFront = Temp->m_pNext;

		delete(Temp);
		--m_iSize;

		if (m_iSize == 0)
			m_pBack = nullptr;
		return iResult;
	}
	int size() 
	{
		return m_iSize;
	}
	int empty() 
	{
		return m_iSize == 0;
	}
	int front() 
	{
		if (nullptr == m_pFront)
			return -1;
		return m_pFront->m_iNum;
	}
	int back() 
	{
		if (nullptr == m_pBack)
			return -1;
		return m_pBack->m_iNum;
	}


private:
	NODE* m_pFront{ nullptr };
	NODE* m_pBack{ nullptr };
	int m_iSize{ 0 };
};



void Solve(ifstream* pLoadStream)
{
	/*
	Å¥ ±¸Çö
	push
	pop
	size
	empty
	front
	back
	*/
	
	CMyQueue myQueue;
	int iSize{};
	int iInput{};
	string szInput{};
	CIN >> iSize;
	for (int i = 0; i < iSize; i++)
	{
		CIN >> szInput;
		if ("push" == szInput)
		{
			CIN >> iInput;
			myQueue.push(iInput);
		}
		else if ("pop" == szInput)
			cout << myQueue.pop() << '\n';
		else if ("size" == szInput)
			cout << myQueue.size() << '\n';
		else if ("empty" == szInput)
			cout << myQueue.empty() << '\n';
		else if ("front" == szInput)
			cout << myQueue.front() << '\n';
		else if ("back" == szInput)
			cout << myQueue.back() << '\n';
	}
}