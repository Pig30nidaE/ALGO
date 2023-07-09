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

//10942

bool    dp[2020][2020] = { false, };
int     arr[2020];
int     n, m;
int     s, e;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i][i] = true;
	}

	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] == arr[i])
			dp[i - 1][i] = true;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; i + j < n; j++)
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1] == 1)
				dp[j][i + j] = true;
	}

	cin>>m;
	for (int i = 0; i < m; i++)
	{
		cin>>s>>e;
		cout<<dp[s - 1][e - 1]<<'\n';
	}
	return 0;
}