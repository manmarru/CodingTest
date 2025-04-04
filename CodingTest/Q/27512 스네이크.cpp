#include "pch.h"
#include "Header.h"

void Solve(ifstream* _pLoadStream)
{
	/*
	스네이크 게임에서 가장 길게 "유지"할 수 있는 뱀의 길이 구하기
	
	한쪽이라도 2 이하이면 꽉 채울 수  있음
	짝수 행 or 열이고 다른 쪽이 3 이상이면 그냥 꽉채울수 있음
	>> 이 두개는 그냥 한쪽이라도 짝수일 경우로 바꿀 수 있다. 코드 더 최적화 가능함


	한쪽이 홀수, 다른쪽이 3 이상이면 한칸 빼고 꽉참

	*/
	int width, height;
	CIN >> width >> height;

	if (width == 2 || height == 2)
		cout << width * height;
	else if (width % 2 == 0 || height % 2 == 0)
		cout << width * height;
	else
		cout << width * height - 1;

}