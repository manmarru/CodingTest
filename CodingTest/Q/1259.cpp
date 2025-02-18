#include "pch.h"
#include "Header.h"
#include <limits>
#include <list>

void Solve(ifstream* pLoadStream)
{
	//�縰��Ҽ� �Ǻ��ϱ�
	//��Ī�� ���� = true
	//�ƴϸ� false

	//�Է� ������ 0

	int iInput(0);
	list<int> listSingleNum;
	while (1)
	{
		(*pLoadStream) >> iInput;
		if (0 == iInput)
			return;
		if (9 >= iInput)
		{
			cout << "yes" << endl;
			continue;
		}


		while (iInput != 0)
		{
			listSingleNum.push_back(iInput % 10);
			iInput /= 10;
		}


		while (1 < listSingleNum.size())
		{
			if (listSingleNum.front() == listSingleNum.back())
			{
				listSingleNum.pop_back();
				listSingleNum.pop_front();
			}
			else
			{
				cout << "no" << endl;
				break;
			}
		}
		if (1 >= listSingleNum.size())
			cout << "yes" << endl;
		listSingleNum.clear();
	}


}