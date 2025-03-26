#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	string test[3];
	int lastnum(0);


	(*_pLoadStream) >> test[0] >> test[1] >> test[2];

	//주어진 숫자 세개가 다 FizzBuzz 형태인건 불가능하고, 무조건 숫자가 하나 들어옴
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
* 3의 배수이면서 5의 배수이면 FizzBuzz를 출력
* 3의 배수이지만 5의 배수가 아니면 Fizz 출력
* 3의 배수가 아니지만 5의 배수이면 Buzz 출력
* 둘 다 아니면 i 그대로 출력
*/
	bool multy3 = (iLastNum % 3) == 0;
	bool multy5 = (iLastNum % 5) == 0;

	if (multy3 && multy5) // 그냥 15로 나누면 되는거긴 하네
		cout << "FizzBuzz" << endl;
	else if (multy3)
		cout << "Fizz" << endl;
	else if (multy5)
		cout << "Buzz" << endl;
	else
		cout << iLastNum << endl;
}
