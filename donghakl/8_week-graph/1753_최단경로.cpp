#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue <pair<int, int>, vector <pair<int, int > >, compare> pq;
	int start;
	int	NodeOne, NodeTwo, Distance;
	int n, m;
	int v, w;
	int next_v, next_w;
	cin >> n >> m;
	vector <pair <int, int> > graph[n];
	int *path = new int[n] ();
	int *dist = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = -1;
	}

	cin >> start;
	for (int i = 0; i < m; i++)
	{
		cin >> NodeOne >> NodeTwo >> Distance;
		graph[NodeOne - 1].push_back(make_pair(NodeTwo - 1, Distance));
	}

	// 시작지점 세팅
	pq.push(make_pair(start - 1, 0));
	dist[start - 1] = 0;
	path[start - 1] = 0;

	// 다익스트라 시작
	while (!pq.empty())
	{
		v = pq.top().first;
		w = pq.top().second;
		pq.pop();
		if (dist[v] < w && dist[v] != -1)
			continue;
		for (int i = 0; i < graph[v].size(); i++)
		{
			next_v = graph[v][i].first;
			next_w = graph[v][i].second;
			if (w + next_w < dist[next_v] || dist[next_v] == -1)
			{
				dist[next_v] = w + next_w;
				pq.push(make_pair(next_v, dist[next_v]));
				path[next_v] = v;
			}
		}
	}

	// 출력단
	for (int i = 0; i < n; i++)
	{
		if (i != start - 1 && dist[i] == -1 && path[i] == 0)
		{
			printf("INF\n");
		}
		else
			printf("%d\n",dist[i]);
	}
}
