#include "pch.h"
#include "Header.h"

#include <iostream>

using namespace std;

/*
1. insert
2. pop
3. size
4. empty
5. top
*/

struct NODE
{
	int Data;
	NODE* Next = nullptr;
	void Free()
	{
		if (Next == nullptr)
			return;
		Next->Free();
		delete Next;
	}
};

class MyStack
{
public:
	MyStack() {};
	~MyStack() 
	{
		if (m_top == nullptr)
			return;
		m_top->Free();
		delete m_top;
	};

public:
	void insert(int Data)
	{
		NODE* Instance = new NODE();
		Instance->Data = Data;
		Instance->Next = m_top;
		m_top = Instance;
		++m_Size;
	}
	void pop()
	{
		if (m_Size == 0)
		{
			cout << -1 << '\n';
			return;
		}
		cout << m_top->Data << '\n';
		NODE* Temp = m_top;
		m_top = m_top->Next;
		delete Temp;
		--m_Size;
	}
	void size() { cout << m_Size << '\n'; }
	void empty()
	{
		cout << (m_Size == 0 ? 1 : 0) << '\n';
	}
	void top()
	{
		if (m_Size == 0)
		{
			cout << -1 << '\n';
			return;
		}
		cout << m_top->Data << '\n';
	}

private:
	int m_Size{ 0 };
	NODE* m_top{ nullptr };

};

void Solve(ifstream* _pLoadStream)
{
	MyStack stack;
	int QuerySize;
	int Input;
	int InputValue;
	CIN >> QuerySize;
	for (int i = 0; i < QuerySize; ++i)
	{
		CIN >> Input;
		switch (Input)
		{
		case 1:
			CIN >> InputValue;
			stack.insert(InputValue);
			break;
		case 2:
			stack.pop();
			break;
		case 3:
			stack.size();
			break;
		case 4:
			stack.empty();
			break;
		case 5:
			stack.top();
			break;
		}
	}
}