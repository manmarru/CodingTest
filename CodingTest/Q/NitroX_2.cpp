#include "pch.h"
#include "Header.h"
#include <vector>

vector<int> Solution(vector<vector<int>> chocolate, int n);

/*
벽돌 초콜릿의 각 조각에 점수가 부여되어 있고 해당 조각을 먹으면 그 점수를 획득한다.
a가 n조각을 먹고 그 다음 b가 n 조각을 먹는다.
어디부터 먹는지는 상관 없다. (중앙부터 먹을수도 있다.) 하지만 먹은 칸과 상하좌우 중에 붙어 있는 칸을 먹어야 한다.
따라서 a 는 b가 연속으로 n칸을 먹을 수 있게 덩어리를 남겨놔야 한다.
b가 얻을 수 있는 가장 높은 점수를 구하시오.
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
