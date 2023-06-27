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

//1263

int	T, ans;
vector<pair<int, int> > ts;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;

	for (int i = 0; i < T; i++)
	{
		int t, s;
		cin>>t>>s;
		ts.push_back(make_pair(s, t));
	}
	
	sort(ts.begin(), ts.end());

	ans = ts[T - 1].first;

	for (int idx = T - 1; idx >= 0; idx--)
	{
		ans -= ts[idx].second;
		if (ans >= ts[idx - 1].first)
			ans = ts[idx - 1].first;
	}
	if (ans < 0)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}

//3 5   5  3
//8 14  14 8
//1 16  16 1
//5 20  20 5
