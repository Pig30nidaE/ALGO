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

#define MAX 20002
#define INF 10000000

int v, e, start;
vector<pair<int, int>> adj[20001];
int	dis[20001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>v>>e>>start;
	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(w, v));
	}
	for (int i = 1; i <= v; i++)
		dis[i] = INF;
    
	dis[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(dis[start], start));
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        int dist = cur.first;
        int idx = cur.second;
        if (dis[idx] != dist)
            continue;
        for (int i = 0; i < adj[idx].size(); i++)
        {
            pair<int, int> next = adj[idx][i];
            int cost = next.first;
            int nidx = next.second;
            if (dis[nidx] > dist + cost)
            {
                dis[nidx] = dist + cost;
                pq.push(make_pair(dis[nidx], nidx));
            }
        }
    }
    for (int i = 1; i <= v; i++) {
		if (dis[i] == INF)
			cout << "INF\n";
		else
			cout << dis[i] << "\n";
	}

	return 0;
}