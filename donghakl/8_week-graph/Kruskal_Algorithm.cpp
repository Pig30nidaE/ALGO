#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int GetParent(int parent[], int x)
{
	if (parent[x] == x)
		return (x);
	return (parent[x] = GetParent(parent, parent[x]));
}

void UnionParent(int parent[], int a, int b) {
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;

}


int FindParent(int parent[], int a, int b)
{
	a = GetParent(parent, a);
	b = GetParent(parent, b);
	if (a == b)
		return (1);
	return (0);
}

struct compare{
	bool operator()(pair<int, int>a, pair<int, int>b){
		return a.second>b.second;
	}
};

class Edge {
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int distance)
		{
			this->node[0] = a;
			this->node[1] = b;
			this->distance = distance;
		}
		bool operator<(const Edge& edge) const {
 			return this->distance < edge.distance;
}
};

int main()
{
	int n = 7;
	int m = 11;

	// vector <pair<pair <int ,int >, int > > graph[?];
	vector <Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end()); // 간선의 비용을 기준으로 오름차순 정렬한다. 
	// Edge클래서의 operator를 설정해서 알아서 distance를 기준으로 정렬한다.

	// 각 정점이 포함된 그래프가 어디인지 저장한다.
	int parent[n]; 
	for (int i = 0; i < n; i++)
		parent[i] = i; // 그래프 배열 초기화

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{	// 사이클이 발생하지 않는 경우 그래프에 포함한다.
		if (!FindParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
			sum += v[i].distance;
		UnionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
	}
	printf("sum: %d\n", sum);
}