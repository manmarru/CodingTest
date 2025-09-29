#include "pch.h"
#include "Header.h"

class Obj
{
public:
	constexpr Obj(int i) { Data = i; };
	constexpr ~Obj() {};

	int Data;
};

void Solve(ifstream* _pLoadStream)
{
	constexpr Obj C(1);

	int Temp[C.Data];
}