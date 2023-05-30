#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#define int long long

int arr[1010][1010];
int	res[1010][1010] = { 0, };

int	n, m;

void	fillresrow()
{
	int	max;
	int	mi;
	int	mj;
	for (int i = 0; i < n; i++)
	{
		max = 0;
		for (int j = 0; j < m; j++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				mi = i;
				mj = j;
			}
			if (j == m - 1)
				res[mi][mj] = 1;
		}
	}
}

void	fillrescol()
{
	int	max;
	int	mi;
	int	mj;
	for (int j = 0; j < m; j++)
	{
		max = 0;
		for (int i = 0; i < n; i++)
		{
			if (max < arr[i][j])
			{
				max = arr[i][j];
				mi = i;
				mj = j;
			}
			if (i == n - 1)
				res[mi][mj] = 1;
		}
	}
}

void	solve()
{
	int sum = 0;
	fillresrow();
	fillrescol();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (res[i][j] != 1)
				sum += arr[i][j];
		}
	}
	cout<<sum;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin>>arr[i][j];
		}
	}

	solve();
}
