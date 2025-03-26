#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	string test[3];
	int lastnum(0);


	(*_pLoadStream) >> test[0] >> test[1] >> test[2];

	//�־��� ���� ������ �� FizzBuzz �����ΰ� �Ұ����ϰ�, ������ ���ڰ� �ϳ� ����
	for (size_t i = 0; i < 3; i++)
	{
		//isDigi
		if (test[i].front() != 'F' && test[i].front() != 'B')
		{
			lastnum = stoi(test[i]) + 3 - i;
			Printing(lastnum);
			return;
		}
	}	


	Printing(lastnum);

}

void Printing(int iLastNum)
{
	/*
* 3�� ����̸鼭 5�� ����̸� FizzBuzz�� ���
* 3�� ��������� 5�� ����� �ƴϸ� Fizz ���
* 3�� ����� �ƴ����� 5�� ����̸� Buzz ���
* �� �� �ƴϸ� i �״�� ���
*/
	bool multy3 = (iLastNum % 3) == 0;
	bool multy5 = (iLastNum % 5) == 0;

	if (multy3 && multy5) // �׳� 15�� ������ �Ǵ°ű� �ϳ�
		cout << "FizzBuzz" << endl;
	else if (multy3)
		cout << "Fizz" << endl;
	else if (multy5)
		cout << "Buzz" << endl;
	else
		cout << iLastNum << endl;
}
