#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

// 1706

int R, C;
vector<string> puz;
vector<string> dic;
//R 4  C 5
void fill_dic()
{
	for (int i = 0; i < R; i++)
	{
		string word = "";
		for (int j = 0; j < C; j++)
		{
			if (puz[i][j] != '#')
			{
				word.push_back(puz[i][j]);
				if (j == C - 1)
				{
					if (word.length() > 1)
					{
						dic.push_back(word);
						word.clear();
					}
					word.clear();
				}
			}
			else if (puz[i][j] == '#')
			{
				if (word.length() > 1)
				{
					dic.push_back(word);
					word.clear();
				}
				word.clear();
			}
		}
	}

	for (int i = 0; i < C; i++)
	{
		string word = "";
		for (int j = 0; j < R; j++)
		{
			if (puz[j][i] != '#')
			{
				word.push_back(puz[j][i]);
				if (j == R - 1)
				{
					if (word.length() > 1)
					{
						dic.push_back(word);
						word.clear();
					}
					word.clear();
				}
			}
			else if (puz[j][i] == '#')
			{
				if (word.length() > 1)
				{
					dic.push_back(word);
					word.clear();
				}
				word.clear();
			}
		}
	}
	sort(dic.begin(), dic.end());
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string input;
		cin >> input;
		puz.push_back(input);
	}

	fill_dic();

	// for (int i = 0; i < dic.size(); i++)
	// 	cout<<dic[i]<<'\n';

	cout << dic[0];

	return 0;
}
