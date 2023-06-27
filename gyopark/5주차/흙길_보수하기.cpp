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

//1911

int	N, L;
int ans = 0;
vector<pair<int, int> > mud; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>L;
	for (int i = 0; i < N; i++)
	{
		int start, end;
		cin>>start>>end;
		mud.push_back(make_pair(start, end));
	}

	sort(mud.begin(), mud.end()); // sort used

	int idx = 0;

	for (int i = 0; i < N; i++)
	{
		if (idx >= mud[i].second)
			continue;

		idx = max(idx, mud[i].first);
	
		int cnt = (mud[i].second - (idx + 1)) / L + 1;
		ans += cnt;
		idx += L * cnt;
	}
	
	cout<<ans<<'\n';

	return 0;
}