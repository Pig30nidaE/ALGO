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
	vector <pair <int, int> > graph[5];
	graph[0].push_back(make_pair(1, 5));
	graph[0].push_back(make_pair(2, 7));
	graph[0].push_back(make_pair(3, 3));

	graph[1].push_back(make_pair(0, 5));
	graph[1].push_back(make_pair(2, 1));
	graph[1].push_back(make_pair(4, 4));

	graph[2].push_back(make_pair(0, 7));
	graph[2].push_back(make_pair(1, 1));
	graph[2].push_back(make_pair(3, 2));
	graph[2].push_back(make_pair(4, 3));

	graph[3].push_back(make_pair(0, 3));
	graph[3].push_back(make_pair(2, 2));

	graph[4].push_back(make_pair(1, 4));
	graph[4].push_back(make_pair(2, 3));

	int visited[5] = {0, };
	int weight[5] = {0, };
	int v, w;
	int next_v, next_w;
	int sum = 0;
	priority_queue <pair<int, int>, vector <pair<int, int > >, compare> pq;
	// start

	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		v = pq.top().first;
		w = pq.top().second;
		pq.pop();
		printf("!! v:%d, w:%d !!\n", v, w);
		if (visited[v] != 0) // 방문 한 적  있으면 넘김
			continue;
		weight[v] = w; // 가중치 표시
		visited[v] = 1; // 방문 표시
		for (int i = 0; i < graph[v].size(); i++)
		{
		// 현재 v가 연결된 정점을 순회하면서 방문하지 않은 정점과 가중치를 pq에 담아준다.
			next_v = graph[v][i].first;
			next_w = graph[v][i].second;
			printf("next_v:%d, next_w:%d\n", next_v, next_w);
			if (visited[next_v] == 0)
				pq.push(make_pair(next_v, next_w));
		}
	}
	for (int i = 0; i < 5; i++)
	{
		sum += weight[i];
	}
	printf("sum: %d\n", sum);
}