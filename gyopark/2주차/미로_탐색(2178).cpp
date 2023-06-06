#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define X first
#define Y second
//define 뒤에는 세미콜론을 붙히지 말자
using namespace std;

string	board[102];
int		dis[102][102]; 
//vis 배열의 합이 그 타일까지의 거리라는 것을 착안해 만들어진 거리 배열
int 	dx[4] = {1, 0, -1, 0};
int 	dy[4] = {0, 1, 0, -1};
int		r, c;
queue<pair<int, int>> q;

void	bfs(int x, int y)
{
	dis[x][y] = 1; // 미로는 항상 0,0에서 시작, 시작 타일도 치므로 거리 1
	q.push({x, y});
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int	ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) 
				continue;
			if (dis[nx][ny] || board[nx][ny] != '1')
				continue;
			// cout<<nx<<ny<<dis[nx][ny]<<'\n';
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
	cout<<dis[r - 1][c - 1];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>r>>c;
	for (int i = 0; i < r; i++)
			cin>>board[i];
	bfs(0, 0);
	return 0;
}


// 36번째 조건식에 대한 chatgpt 대답
// 주어진 코드에서 dis는 각 타일의 시작 타일로부터의 거리를 저장하는 배열입니다. if 문인 if (dis[nx][ny] || board[nx][ny] != '1')의 목적은 현재 타일 (nx, ny)이 이미 방문된 타일인지 (dis[nx][ny] != 0) 또는 이동할 수 없는 유효하지 않은 타일인지 (board[nx][ny] != '1')를 확인하는 것입니다.

// 다음은 이러한 조건이 사용되는 이유에 대한 설명입니다:

// dis[nx][ny]: dis[nx][ny]가 0이 아닌 경우, 이전 반복에서 이미 해당 타일을 방문했음을 의미합니다. 따라서 해당 타일로 이동하는 최단 거리를 이미 찾았으므로 다시 방문할 필요가 없습니다. 이미 방문된 타일을 건너뛰는 것은 불필요한 탐색을 피하고 그래프 순회 과정에서 무한 루프를 방지하는 데 도움이 됩니다.

// board[nx][ny] != '1': 이 조건은 (nx, ny) 위치의 타일이 이동할 수 있는 유효한 타일인지를 확인합니다. 주어진 코드의 맥락에서 '1'은 유효한 타일을 나타낼 가능성이 있으며, 다른 문자는 장애물이나 유효하지 않은 타일을 나타낼 수 있습니다. board[nx][ny] != '1'을 확인함으로써 이동할 수 있는 타일만 고려합니다.

// 이 두 가지 조건을 결합함으로써, 코드는 이미 탐색된 타일을 재방문하지 않고 유효하지 않은 타일을 건너뛰어 미로를 효율적으로 탐색하고 목적지까지의 최단 경로를 찾을 수 있습니다.