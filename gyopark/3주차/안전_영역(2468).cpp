#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

#define X first
#define Y second

int		board[102][102];
bool	vis[102][102];
int		r, c, res, tmp;
int		dx[4] = {1, 0, -1, 0};
int		dy[4] = {0, 1, 0, -1};
// stack<pair<int, int> > s;

void	clear_board()
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			vis[i][j] = 0;
	tmp = 0;
}

void	dfs(int x, int y, int num)
{
	vis[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int	ny = y + dy[dir];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		if (vis[nx][ny] != 0 || board[nx][ny] <= num)
			continue;
		vis[nx][ny] = 1;
		dfs(nx, ny, num);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int N;
	int max = 0;
	res = 0; tmp = 0;

	cin>>N; c = N; r = N;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin>>board[i][j];
			if (board[i][j] > max)
				max = board[i][j];
		}
	}

	for (int i = 0; i < max + 1; i++)
	{
		for (int n = 0; n < r ; n++)
		{
			for (int m = 0; m < c; m++)
			{
				if (vis[n][m] == 0 && board[n][m] > i)
				{
					tmp++;	
					dfs(n, m, i);
				}
			}
			if (res < tmp)
				res = tmp;
		}	
		clear_board();
	}
	cout<<res;
	return 0;
}