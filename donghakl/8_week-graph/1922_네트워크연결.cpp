#include <iostream>
#include <algorithm>
#include <vector>

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
		// void	GetStart(int n) {this->node[0] = n;}
		// void	GetEnd(int n) {this->node[1] = n;}
		// void	GetDistance(int n) {this->distance = n;}
		bool	operator<(const Edge& edge) const {
 			return this->distance < edge.distance;
}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector <Edge >	v;
	int				n; // 컴퓨터 수
	int				m; // 간선 수
	int				start;
	int				end;
	int				distance;


	cin >> n;
	int *parent = new int[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> start;
		cin >> end;
		cin >> distance;
		v.push_back(Edge(start - 1, end - 1, distance));
	}
	sort(v.begin(), v.end());

	// for (vector <Edge>::iterator i = v.begin(); i < v.end(); i++)
	// {
	// 	printf("%d, %d, %d\n", i->node[0], i->node[1], i->distance);
	// }

	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{	// 사이클이 발생하지 않는 경우 그래프에 포함한다.
		if (!FindParent(parent, v[i].node[0], v[i].node[1]))
			sum += v[i].distance;
		UnionParent(parent, v[i].node[0], v[i].node[1]);
	}

	printf("%d\n", sum);
}