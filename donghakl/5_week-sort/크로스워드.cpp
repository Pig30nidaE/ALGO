#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[21][21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string tmp;

	int r, c;
	cin >> r >> c;
	string *str = new string[r];
	for (int i = 0; i < r; i++)
	{
	
		cin >> tmp;
		str[i] = tmp;

	}

	int index;
	int value;
	int min = 'z';
	int tmp2;
	vector <string> vec;
	string word;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (str[j][i] == '#')
			{
				if (word.length() > 1)
				{
					vec.push_back(word);
				}
				word.clear();
			}
			else
			{
				word.push_back(str[j][i]);
			}
		}
		if (word.length() > 1)
		{
			vec.push_back(word);
		}
		word.clear();
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (str[i][j] == '#')
			{
				if (word.length() > 1)
				{
					vec.push_back(word);
				}
				word.clear();
			}
			else
			{
				word.push_back(str[i][j]);
			}
		}
		if (word.length() > 1)
		{
			vec.push_back(word);
		}
		word.clear();
	}
	sort(vec.begin(), vec.end());


	cout << vec[0] << "\n";
}