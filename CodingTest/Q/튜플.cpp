#include "pch.h"
#include "Header.h"
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

void Solve(ifstream* _pLoadStream)
{
	string s;
	CIN >> s;

	s = s.substr(1, s.length() - 2);
	int StringLength = s.size();
	vector<vector<int>> Inputs;

	for (int i = 0; i < StringLength; ++i)
	{
		i += 1; // { »ý·«
		string Temp;
		vector<int> Input;
		while (1)
		{
			if (s[i] == '}')
			{
				Input.push_back(stoi(Temp));
				Temp.clear();
				Inputs.push_back(Input);
				++i;
				break;
			}
			else if (s[i] == ',')
			{
				Input.push_back(stoi(Temp));
				Temp.clear();
			}
			else
			{
				Temp += s[i];
			}
			++i;
		}
	}

	sort(Inputs.begin(), Inputs.end(), [](vector<int> Temp, vector<int> Src) {return Temp.size() < Src.size(); });

	int AnswerSize = Inputs.back().size();
	unordered_set<int> History;
	vector<int> Answer;

	for (auto& Temp : Inputs)
	{
		for (int i : Temp)
		{
			if (History.find(i) == History.end())
			{
				History.insert(i);
				Answer.push_back(i);
			}
		}
	}

	//return Answer
}