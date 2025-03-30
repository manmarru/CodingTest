#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	오늘은 내가 팬케이크 요리사!
	문제 쓰레기같아!
	우유8 계란 노른자 8 설탕 4 소금 1 밀가루 9 = 팬케이크 반죽 16개
	팬케이크에 사용하는 각 장식
	- 바나나 1
	- 딸기 30
	- 초콜릿 25
	- 호두 10
	모든 재료의 양을 입력받고 만들 수 있는 팬케이크의 수 출력하기
	*/
	int Case;
	float IngredientNeed[5]{ 8, 8, 4, 1, 9 };
	float Ingredient[5];
	float Deco[4];
	float DecoNeed[4]{ 1, 30, 25, 10 };
	float dough{ 1000000 };
	int Pancake{ 0 };

	CIN >> Case;
	for (int i = 0; i < Case; i++)
	{
		dough = 1000000.f;
		Pancake = 0;

		for (int j = 0; j < 5; ++j)
		{
			CIN >> Ingredient[j];
			dough = min(Ingredient[j] / IngredientNeed[j], dough);
		}
		dough = int(dough * 16);
		int Make = 0;
		for (int j = 0; j < 4; ++j)
		{
			if (dough <= 0)
				break;
			CIN >> Deco[j];
			Make += (int)(Deco[j] / DecoNeed[j]);
		}

		cout << min(Make, (int)dough) << '\n';
	}
}