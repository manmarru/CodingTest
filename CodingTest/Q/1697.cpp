#include "pch.h"
#include "Header.h"
#include <queue>
#include <vector>
#include <set>

#pragma region 다른사람 풀이

/*
https://www.acmicpc.net/source/90849313
// Authored by : daeguhighman
#include <bits/stdc++.h>
using namespace std;
int N, K;
bool vis[100002];
int dist[100002];
queue <int > Q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	fill(dist, dist + 100000, -1);
	dist[N] = 0;
	Q.push(N);
	vis[N] = true;
	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		// cout << cur << '\n';
		if (cur - 1 >= 0 && cur - 1 <= 100000 && vis[cur - 1] == 0) {
			Q.push(cur - 1);
			dist[cur - 1] = dist[cur] + 1;
			vis[cur - 1] = true;
			if (cur - 1 == K) break;
		}
		if (cur + 1 <= 100000 && vis[cur + 1] == 0) {
			Q.push(cur + 1);
			dist[cur + 1] = dist[cur] + 1;
			vis[cur + 1] = true;
			if (cur + 1 == K) break;
		}
		if (2 * cur <= 100000 && vis[2 * cur] == 0) {
			Q.push(2 * cur);
			dist[2 * cur] = dist[cur] + 1;
			vis[2 * cur] = true;
			if (2 * cur == K) break;
		}
	}
	cout << dist[K];
}
*/
#pragma endregion

void Solve(ifstream* pLoadStream)
{
	/*
	1초마다 +-1 이동 or *2 이동
	목적지로 가는 가장 빠른 시간 구하기
	0 <= n <= 100000
	*/

	int iStart, iEnd;
	int iResult{ 0 };
	CIN >> iStart >> iEnd;

	set<int> setHistory;
	queue<int> stlDestination;
	stlDestination.push(iStart);

	int iCurr;
	bool bBlocked;
	while (1)
	{
		queue<int> stlTemp;
		while (!stlDestination.empty())
		{
			iCurr = stlDestination.front();
			if (iCurr == iEnd)
			{
				cout << iResult;
				return;
			}
			stlDestination.pop();
			if (iCurr > 0 && setHistory.find(iCurr - 1) == setHistory.end())
			{
				setHistory.insert(iCurr - 1);
				stlTemp.push(iCurr - 1);
			}
			if (iCurr < 100000 && setHistory.find(iCurr + 1) == setHistory.end())
			{
				setHistory.insert(iCurr + 1);
				stlTemp.push(iCurr + 1);
			}
			if (iCurr * 2 <= 100000 && setHistory.find(iCurr * 2) == setHistory.end())
			{
				setHistory.insert(iCurr * 2);
				stlTemp.push(iCurr * 2);
			}
		}
		swap(stlDestination, stlTemp);
		++iResult;
	}
}