#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

// 1431

int N;
string	g[55];

bool	compare(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();

	int asum = 0, bsum = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
			asum += (int)a[i] - '0';
		if (b[i] >= '0' && b[i] <= '9')
			bsum += (int)b[i] - '0';
	}

	if (asum != bsum)
		return (asum < bsum);
	
	return (a < b);
}

int	main(void)
{
	cin>>N;
	for (int i = 0; i < N; i++)
		cin>>g[i];

	sort(g, g+N, compare);

	for (int i = 0; i < N; i++)
		cout<<g[i]<<'\n';
	return 0;
}