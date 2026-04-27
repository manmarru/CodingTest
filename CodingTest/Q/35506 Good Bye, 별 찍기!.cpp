#include "pch.h"
#include "Header.h"


void Left(int _input, int _line);
void Right(int _input, int _line);

void Solve(ifstream* _pLoadStream)
{
	int input;
	CIN >> input;
	input *= 2;
	
	for (int i = 1; i <= input; ++i)
	{
		Left(input, i);
		Right(input, i);
		cout << '|';
		cout << endl;

	}


}

void Left(int _input, int _line)
{
	int blink = _input - _line;
	for (int i = 1; i <= blink; ++i)
	{
		cout << ' ';
	}

	cout << '*';

	for (int i = 0; i < _line; ++i) {
		cout << ' ';
	}
}

void Right(int _input, int _line)
{
	int blink;
	if (_line > _input / 2) {
		blink = _line - (_input / 2) - 1;
	}
	else {
		blink = (_input / 2) - _line;
	}

	for (int i = 1; i <= blink; ++i) 
	{
		cout << ' ';
	}
	cout << '*' << ' ';

	int middleblink = _input / 2 - blink - 1;
	
	for (int i = 1; i <= middleblink * 2; ++i)
	{
		cout << ' ';
	}

	cout << '*';
	for (int i = 1; i <= blink; ++i)
	{
		cout << ' ';
	}
}