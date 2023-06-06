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

int	board[55][55];
bool	vis[55][55] = { 0, };
int	dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};
int	r,c,N;
int	res;
queue<pair<int, int>> Q;

void	bfs(int x, int y)
{
	// x = r, y = c;
	vis[x][y] = true;
	Q.push({x, y});
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			//x는 r이고, y는 c다
			if (vis[nx][ny] || board[nx][ny] != 1)
				continue;
			vis[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
}

void	clean_board_vis(int r, int c)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			vis[i][j] = false;
		}
	}
}

// *중요* board[i][j]에서 i는 세로, j는 가로이다
// r은 세로, c는 가로이다.
// 우리가 생각하는 x, y는 x가 가로, y가 세로이다
// 예제에서 0 0, 1 0, 1 1, 이런식으로 들어오는데
// 앞이 가로고 뒤가 세로다 그래서 board[y][x]로 받아야한다
// 행열 문제에서 x가 가로, y가 세로라는 상식은 방해물이다.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int	t;
	cin>>t;
	while (t--)
	{
		cin>>c>>r>>N;
		res = 0;
		for (int i = 0; i < N; i++)
		{
			int x, y;
			cin>>x>>y;
			board[y][x] = 1;
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == 1 && !vis[i][j])
				{
					bfs(i, j);
					res++;
				}
			}
		}
		cout<<res<<'\n';
		clean_board_vis(r, c);
	}
	return 0;
}
