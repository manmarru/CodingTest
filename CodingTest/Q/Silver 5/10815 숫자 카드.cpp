#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>
/*
https://www.acmicpc.net/problem/10815
ㅇㅋ 이진탐색 굿
이거 라이브러리에 있는거 나중에 써보는것도 고려해보셈 더 빠르니깐
*/
void Solve(ifstream* _pLoadStream)
{
	int CardSize;
	CIN >> CardSize;
	vector<int> Cards(CardSize);
	for (int i = 0; i < CardSize; ++i){
		CIN >> Cards[i];
	}
	sort(Cards.begin(), Cards.end());

	int InputSize;
	CIN >> InputSize;
	vector<int> Input(InputSize);
	for (int i = 0; i < InputSize; ++i)
		CIN >> Input[i];

	int Mid = CardSize - 1;
	for (int Curr : Input)
	{
		int Left{ 0 }, Right{ CardSize - 1 };
		while (Left <= Right)
		{
			Mid = (Left + Right) / 2;
			if (Curr == Cards[Mid])
				break;
			else if (Curr < Cards[Mid])
				Right = Mid - 1;
			else
				Left = Mid + 1;
		}

		cout << (Curr == Cards[Mid]) ? 1 : 0;
	}
}