#include "pch.h"
#include "Header.h"
#include <vector>

struct NODE
{
	int Cost = 0;
};

struct LINK
{
	int Start;
	int End;
	int Cost;
};

void Solve(ifstream* _pLoadStream)
{
	int Size;
	CIN >> Size;
	int NodeSize, LinkSize, WormSize;
	int Input[3];
	for (int Case = 0; Case < Size; ++Case)
	{
		CIN >> NodeSize >> LinkSize >> WormSize;
		vector<NODE> Nodes(NodeSize);
		vector<LINK> Links(LinkSize + WormSize);
		for (int i = 0; i < LinkSize; ++i)
		{
			CIN >> Links[i].Start >> Links[i].End >> Links[i].Cost;
			--Links[i].Start; --Links[i].End;
		}
		for (int i = LinkSize; i < WormSize + LinkSize; ++i)
		{
			CIN >> Links[i].Start >> Links[i].End >> Links[i].Cost;
			--Links[i].Start; --Links[i].End;
			Links[i].Cost *= -1;
		}
		for (int i = 0; i < LinkSize; ++i)
		{
			Links.push_back({ Links[i].End, Links[i].Start, Links[i].Cost });
		}

		for (int i = 0; i < NodeSize; ++i)
		{
			for (LINK& Link : Links)
			{
				Nodes[Link.End].Cost = min(Nodes[Link.Start].Cost + Link.Cost, Nodes[Link.End].Cost);
			}
		}

		bool Result = false;
		for (LINK& Link : Links)
		{
			if (Nodes[Link.End].Cost > Nodes[Link.Start].Cost + Link.Cost)
			{
				Result = true;
				break;
			}
		}
		if (Result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}