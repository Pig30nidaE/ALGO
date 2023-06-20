#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair <int, string> a, pair <int, string> b)
{
	int a_sum;
	int b_sum;

	if (a.second.length() != b.second.length())
		return a.second.length() < b.second.length();
	else
	{
		a_sum = a.first;
		b_sum = b.first;
		if (a_sum != b_sum)
		{
			return a_sum < b_sum;
		}
		else
		{ 
			return a.second < b.second; 
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string str;
	int cnt;
	cin >> n;
	vector <pair <int, string> > vec;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cnt = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (0 < str[j] - '0' && str[j] - '0' < 10)
			{
				cnt += str[j] - '0';
			}
		}
		vec.push_back(make_pair(cnt, str));
	}

	sort (vec.begin(), vec.end(), cmp);

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].second << "\n";
	}
}