#include "pch.h"
#include "Header.h"
#include <vector>
#include <algorithm>


void Solve(ifstream* _pLoadStream)
{
	/*
	곡 길이가 Length인 노래를 Size 개를 듣는다. 각 노래 사이에는 5초의 정적이 있다.
	동시에 벨소리가 Gap초 마다 1초씩 울린다.
	최초로 정적시간에 벨소리가 울리는 시간을 구하기(없으면 노래가 다 끝날 때)

	연산순서를 자꾸 틀려서 엄청 고생했다.
	수학적인 접근 시도는 좋았지만
	이럴거면 차라리 bool 배열에다가 매 초 상황을 넣어서 체크하는게 더 나았을듯?
	*/
	int Size;
	int Length;
	int Gap;

	CIN >> Size >> Length >> Gap;

	int Curr{ 0 };

	int RemainGap;
	for (int i = 0; i < Size; ++i)
	{
		Curr += Length;
		if (Curr % Gap == 0)
		{
			cout << Curr;
			return;
		}
		RemainGap = Gap - Curr % Gap;
		if (RemainGap < 5)
		{
			cout << Curr + RemainGap;
			return;
		}

		Curr += 5;
	}
	Curr -= 5;
	cout << Curr + RemainGap;
}