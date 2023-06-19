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

// 1431

int N;
string	g[55];

int	isBig(string a, string b)
{
	int asum = 0, bsum = 0;

	if (a.size() != b.size())
		return a.size() > b.size();

	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			asum += a[i] - '0';
		if (b[i] >= '0' && b[i] <= '9')
			bsum += b[i] - '0';
	}

	if (asum != bsum)
		return asum > bsum;
	return (a > b);
}

void	InsertionSort(string* g)
{
	int i, j;
	string	key;

	for (int i = 1; i < N; i++)
	{
		key = g[i];
		for (j = i - 1; j >= 0 && isBig(g[j], key); j--)
			g[j + 1] = g[j];
		g[j + 1] = key;
	}
}


int	main(void)
{
	cin>>N;
	
	for (int i = 0; i < N; i++)
		cin>>g[i];

	InsertionSort(g);

	for (int i = 0; i < N; i++)
		cout<<g[i]<<'\n';
	return 0;
}