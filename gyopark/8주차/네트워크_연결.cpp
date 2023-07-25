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

// 1923

#define X first
#define Y second

int v,e;
vector<pair<int, int>> adj[10005];
bool chk[10005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>v>>e;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin>>a>>b>>cost;
		adj[a].push_back(make_pair(cost, b));
		adj[b].push_back(make_pair(cost, a));
	}

	int cnt = 0;
	int ans = 0;

	priority_queue< tuple<int, int, int>,
					vector<tuple<int,int,int>>,
					greater<tuple<int,int,int>> > pq;

	chk[1] = 1;
	for (int i = 0; i < adj[1].size(); i++)
	{
		int nxtCost = adj[1][i].first;
		int nxtidx = adj[1][i].second;
		pq.push(make_tuple(nxtCost, 1, nxtidx));
	}

    while (cnt < v - 1) {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b]) continue;
        ans += cost;
        chk[b] = 1;
        cnt++;
        for (int i = 0; i < adj[b].size(); i++) {
            int nxtCost = adj[b][i].first;
            int nxtidx = adj[b][i].second;
            if (!chk[nxtidx])
                pq.push(make_tuple(nxtCost, b, nxtidx));
        }
    }
	cout<<ans;
	return 0;
}