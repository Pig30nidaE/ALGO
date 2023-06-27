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

int R, C;
vector<string> puz;
vector<string> dic;

void fill_dic()
{
    for (int i = 0; i < R; i++)
    {
        string word = "";
        string Rword = "";
        for (int j = 0; j < C; j++)
        {
            if (puz[i][j] != '#')
                word.push_back(puz[i][j]);
            else
            {
                while (j < C && puz[i][j] == '#')
                    j++;
                if (j < C)
                    for (int idx = j; idx < C; idx++)
                        Rword.push_back(puz[i][idx]);
                break;
            }
        }
        if (word.length() > 1)
            dic.push_back(word);
        if (Rword.length() > 1)
            dic.push_back(Rword);
    }

    for (int i = 0; i < C; i++)
    {
        string word = "";
        string Rword = "";
        for (int j = 0; j < R; j++)
        {
            if (puz[j][i] != '#')
                word.push_back(puz[j][i]);
            else
            {
                while (j < R && puz[j][i] == '#')
                    j++;
                if (j < R)
                    for (int idx = j; idx < R; idx++)
                        Rword.push_back(puz[idx][i]);
                break;
            }
        }
        if (word.length() > 1)
            dic.push_back(word);
        if (Rword.length() > 1)
            dic.push_back(Rword);
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
	// 	cout<< dic[i] << '\n';

	cout << dic[0];

    return 0;
}
