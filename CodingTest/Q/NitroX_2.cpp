#include "pch.h"
#include "Header.h"
#include <vector>

vector<int> Solution(vector<vector<int>> chocolate, int n);

/*
���� ���ݸ��� �� ������ ������ �ο��Ǿ� �ְ� �ش� ������ ������ �� ������ ȹ���Ѵ�.
a�� n������ �԰� �� ���� b�� n ������ �Դ´�.
������ �Դ����� ��� ����. (�߾Ӻ��� �������� �ִ�.) ������ ���� ĭ�� �����¿� �߿� �پ� �ִ� ĭ�� �Ծ�� �Ѵ�.
���� a �� b�� �������� nĭ�� ���� �� �ְ� ����� ���ܳ��� �Ѵ�.
b�� ���� �� �ִ� ���� ���� ������ ���Ͻÿ�.
*/

void Solve(ifstream* _pLoadStream)
{
	vector<vector<int>> Temp;
	Temp.push_back({ 2, 10, 7 });
	Temp.push_back({ 1, 10, 10 });
	Temp.push_back({ 6, 10, 1 });

	Solution(Temp, 4);
}

vector<int> Solution(vector<vector<int>> chocolate, int n)
{

	vector<int> answer;
	return answer;
}
