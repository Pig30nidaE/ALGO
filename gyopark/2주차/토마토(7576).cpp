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

#define X first
#define Y second

int	board[1001][1001];
int	dis[1001][1001];
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};
int	r, c, ans;
queue<pair<int, int>> q;

void	bfs()
{
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int	nx = cur.X + dx[dir];
			int	ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (dis[nx][ny]>=0)
				continue;
			dis[nx][ny] = dis[cur.X][cur.Y] + 1;
			q.push({nx, ny});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>c>>r;
	ans = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin>>board[i][j];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 1)
				q.push({i, j});
			else if (board[i][j] == 0)
				dis[i][j] = -1;
		}
	}
	bfs();
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (dis[i][j] == -1) // 토마토가 하나라도 익지 않았으면
			{
				cout<<-1;
				return 0;
			}
			ans = max(ans, dis[i][j]);
		}
	}
	cout<<ans;
	return 0;
}