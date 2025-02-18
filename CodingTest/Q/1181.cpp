#include "pch.h"
#include "Header.h"
#include <list>
#include <string>
#include <algorithm>

void Solve(ifstream* pLoadStream)
{
	/*
	���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

	���̰� ª�� �ͺ���
	���̰� ������ ���� ������
	��, �ߺ��� �ܾ�� �ϳ��� ����� �����ؾ� �Ѵ�.
	*/
	
	int iSize(0);
	string strInput;
	list<string> listInput;
	(*pLoadStream) >> iSize;

	for (size_t i = 0; i < iSize; i++)
	{
		(*pLoadStream) >> strInput;
		listInput.push_back(strInput);
	}
	
	//����
	listInput.sort([](string a, string b)
		{
			if (a.size() == b.size())// ����������
			{
				auto iterA = a.begin();
				auto iterB = b.begin();

				for (size_t i = 0; i < a.size(); i++)
				{
					if ((*iterA) == (*iterB))
					{
						iterA++;
						iterB++;
					}
					else
						return (*iterA) < (*iterB);
				}
			}
			return a.size() < b.size();
		});

	list<string>::iterator currentiter;
	//�ߺ�����
	for (auto iter = listInput.begin(); iter != listInput.end();)
	{
		do
		{
			currentiter = iter;
			++iter;
			if (listInput.end() == iter)
				break;
			if ((*currentiter) == (*iter))
			{
				currentiter = listInput.erase(currentiter);
			}
		} while (iter != listInput.end() && (*iter).size() == (*currentiter).size());
	}


	//��ȯ
	for (auto Word : listInput)
		cout << Word << endl;
}