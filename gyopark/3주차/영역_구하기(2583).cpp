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

#define	X first
#define Y second

int		board[102][102];
bool	vis[102][102];
int		dx[4] = {1, 0, -1, 0};
int		dy[4] = {0, 1, 0, -1};
int 	M, N, K, res, tmp;

void	dfs(int x, int y)
{
	vis[x][y] = 1;
	tmp++;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny] == 0 && board[nx][ny] == 1)
		{
			vis[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>M>>N>>K;
	res = 0;
	tmp = 0;
	vector<pair<int, int> > LeftDown(K);
	vector<pair<int, int> > RightUp(K);
	vector<int> ans;

	for (int i = 0; i < M; i++) 
		for (int j = 0; j < N; j++)
			board[i][j] = 1;

	for (int i = 0; i < K; i++)
	{
		cin>>LeftDown[i].Y;
		cin>>LeftDown[i].X;
		cin>>RightUp[i].Y;
		cin>>RightUp[i].X;
	}

	for (int i = 0; i < K; i++)
	{
		int	r = RightUp[i].X;
		int	c = RightUp[i].Y;
		for (int n = LeftDown[i].X; n < r; n++) 
		{
			for (int m = LeftDown[i].Y; m < c; m++)
				board[n][m] = 0;
		}
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == 0 && board[i][j] == 1)
			{
				dfs(i, j);
				ans.push_back(tmp);	
				tmp = 0;
			}
		}
	}
	sort(all(ans));
	cout<<ans.size()<<'\n';
	for (int i = 0; i < ans.size(); i++)
		cout<<ans[i]<<' ';
	return 0;
}
