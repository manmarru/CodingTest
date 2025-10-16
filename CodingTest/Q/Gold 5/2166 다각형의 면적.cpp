#include "pch.h"
#include "Header.h"
#include <vector>
#include <cmath>

//가우스의 신발끈 공식

void Solve(ifstream* _pLoadStream)
{
	int VertexSize;
	CIN >> VertexSize;
	vector<int> CoorX(VertexSize + 1);
	vector<int> CoorY(VertexSize + 1);
	for (int i = 0; i < VertexSize; ++i)
	{
		CIN >> CoorX[i] >> CoorY[i];
	}
	CoorX[VertexSize] = CoorX[0];
	CoorY[VertexSize] = CoorY[0];

	double Result{ 0 };
	for (int i = 0; i < VertexSize; ++i)
	{
		Result += (double)CoorX[i] * (double)CoorY[i + 1] - (double)CoorX[i + 1] * (double)CoorY[i];
	}
	cout << fixed;
	cout.precision(1);
	cout << round(abs((Result / 2.0) * 10)) / 10;
}