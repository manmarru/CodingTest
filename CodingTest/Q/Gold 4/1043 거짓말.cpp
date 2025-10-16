#include "pch.h"
#include "Header.h"
#include <vector>
#include <queue>

struct OBJ
{
	vector<int> Entry;
	bool Truth = false;
};


void Solve(ifstream* _pLoadStream)
{
	/*
	파티에서 거짓말을 할 건데
	진실을 아는 사람이 파티에 같이 있으면 진실을 말해야 한다.
	한 사람이 진실과 거짓을 둘 다 들으면 안된다.
	거짓말을 할 수 있는 최대 파티 수를 구하기
	
	일단 진실을 말해야 하는 파티를 구분하고
	그 파티에 참가 예정인 사람을 모두 진실을 아는 사람으로 구분
	사람 번호는 [1, 50] 이기 때문에 비어있는 0번 인덱스를 넣었다.

	1. 진실을 아는 사람인지 여부를 저장
	2. 진실을 말해야 하는 파티인지 여부를 저장
	3. 파티별 참가하는 사람을 저장
	4. 참가자별 참가하는 파티를 저장
	4. 진실을 말해야 하는 파티를 전부 Destination에 넣음
	Destination.front 부터 파티를 순회
	5. 참가자를 순회하면서 그 사람을 true로 설정
	6. 해당 파티의 참가자들이 참석하는 다른 파티들을 Destination 에 넣고 반복
	7. 정답 출력

	참고로 Union find 를 사용하는 방법과, 사람들간의 연결 그래프를 만들어서 탐색하는 방법이 있다.
	*/

	// 사람의 수 n 과 파티의 수 m
	// 진실을 아는 사람 수화 번호
	// 각 파티마다 진실을 아는 사람 수와 사람의 인덱가 주어짐
	int Mansize, Partysize, TrueMansize;
	int Input;
	CIN >> Mansize >> Partysize;
	vector<OBJ> People(Mansize + 1); // 0번 사람은 없는거임
	vector<OBJ> Parties(Partysize);
	CIN >> TrueMansize;
	for (int i = 0; i < TrueMansize; ++i)
	{
		CIN >> Input;
		People[Input].Truth = true;
	}
	
	int Size;
	for (int party = 0; party < Partysize; ++party)
	{
		CIN >> Size;
		for (int i = 0; i < Size; ++i)
		{
			CIN >> Input;
			Parties[party].Entry.push_back(Input);
			People[Input].Entry.push_back(party);
			if (People[Input].Truth)
			{
				Parties[party].Truth = true;
				for (int Temp : Parties[party].Entry)
					People[Temp].Truth = true;
			}
		}
	}

	queue<int> Destination; // 파티번호
	for(int i = 0; i < Partysize; ++i)
	{
		if (Parties[i].Truth)
			Destination.push(i);
	}

	int Curr;
	while (!Destination.empty())
	{
		Curr = Destination.front();
		Destination.pop();

		for (int i : Parties[Curr].Entry)
		{
			for (int Temp : People[i].Entry)
			{
				if (!Parties[Temp].Truth)
				{
					Destination.push(Temp);
					Parties[Temp].Truth = true;
				}
			}
		}
	}

	int Result(0);
	for (int i = 0; i < Partysize; ++i)
	{
		if (Parties[i].Truth)
			++Result;
	}
	cout << Partysize - Result;
}