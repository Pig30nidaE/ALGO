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
#define INF 987654321

// 1753

int v, e, start;
int map[MAX][MAX]; 
// 지도를 그리는 이중 배열이다
// 정점 i와 j의 거리를 기록한다
int Dist[MAX];
// 정점 start로부터 destination으로 향하는
// 최소 거리를 기록하는 배열이다.
bool visited[MAX];
// 노드의 방문 여부를 체크하는 배열이다.

int find_shortest_node()
{
    int min_dist = INF;
    int min_idx = -1;

    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == true) continue;
        if (Dist[i] < min_dist)
        {
            min_dist = Dist[i];
            min_idx = i;
        }
    }
    return min_idx;
    // -1이 리턴되는 경우 오류 처리
}

void    update_list(int newnode)
{
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == true)
            continue;
        if (Dist[i] > Dist[newnode] + map[newnode][i])
        {
            Dist[i] = Dist[newnode] + map[newnode][i];
        }
    }
}

void	Dijkstra()
{
	for (int i = 1; i <= v; i++)
		Dist[i] = map[start][i];
	// 먼저 출발점을 기준으로 모든 정점까지의 거리 기록
    Dist[start] = 0; //출발점에서 자기자신까지의 거리 0
    visited[start] = true; // 출발점을 방문 처리

    for (int i = 0; i < v - 1; i++)
    {
        int newnode = find_shortest_node();
        // 출발점에서 가장 거리가 짧은 노드의 번호를 반환
        if (newnode < 0) continue ;
        visited[newnode] = true;
        update_list(newnode);
    }
}

void	solve()
{
	Dijkstra();
	for (int i = 1; i <= v; i++)
	{
		if (Dist[i] >= INF)
			cout << "INF" << '\n';
		else 
			cout << Dist[i] << '\n';
	}
}

void    input()
{
	cin>>v>>e; // v는 정점의 개수, e는 간선의 개수이다.
	cin>>start; // 시작점이다
	for (int i = 1; i <= v; i++)
	{
		Dist[i] = INF; // 거리 배열의 초기값은 전부 INF이다.
		for (int j = 1; j<= v; j++)
		{
			if (i == j) 
				map[i][j] = 0;
			// 지도 배열의 초기값 -> 자기 자신 0
			else 
				map[i][j] = INF;
			// 아니라면 INF
		}
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, c; cin>>a>>b>>c;
    	map[a][b] = c;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	solve();

	return 0;
}