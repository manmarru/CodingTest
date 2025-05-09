#include "pch.h"
#include "Header.h"


void Solve(ifstream* _pLoadStream)
{
	/*
	이게 대체 왜 보라식이데?!!
	HSV 계산식을 통해 H, S, V가 범위 안에 들어가는지 확인하기
	*/
	int H_Range[2], S_Range[2], V_Range[2];
	CIN >> H_Range[0] >> H_Range[1] >> S_Range[0] >> S_Range[1] >> V_Range[0] >> V_Range[1];
	int R, G, B;
	int H, S, V, M, m;
	CIN >> R >> G >> B;
	M = max(max(R, G), B);
	m = min(min(R, G), B);


	V = M;
	S = 255 * (V - m) / V;
	
	if (V == R)
	{
		H = (60 * (G - B)) / (V - m);
	}
	else if (V == G)
	{
		H = 120 + (60 * (B - R)) / (V - m);
	}
	else if (V == B)
	{
		H = 240 + (60 * (R - G)) / (V - m);
	}
	while (H < 0)
		H += 360;
	while (H >= 360)
		H -= 360;


	if (H_Range[0] <= H && H <= H_Range[1] && S_Range[0] <= S && S <= S_Range[1] && V_Range[0] <= V && V <= V_Range[1])
		cout << "Lumi will like it.";
	else
		cout << "Lumi will not like it.";

}