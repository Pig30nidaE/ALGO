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

string  board[102];
int     vis[102][102];
int     dx[4] = {1, 0, -1, 0};
int     dy[4] = {0, 1, 0, -1};
int     N, res, res_weak;

void	R_dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny] == 0 && board[nx][ny] == 'R')
			R_dfs(nx, ny);
	}
}

void	G_dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny] == 0 && board[nx][ny] == 'G')
			G_dfs(nx, ny);
	}
}

void	B_dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny] == 0 && board[nx][ny] == 'B')
			B_dfs(nx, ny);
	}
}

void	RG_dfs(int x, int y)
{
	vis[x][y] = 1;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (vis[nx][ny] == 0 && (board[nx][ny] == 'R' || board[nx][ny] == 'G'))
			RG_dfs(nx, ny);
	}
}

void	dfs(int x, int y)
{
	vis[x][y] = 1; 
	if (board[x][y] == 'R')
		R_dfs(x, y);
	else if (board[x][y] == 'G')
		G_dfs(x, y);
	else if (board[x][y] == 'B')
		B_dfs(x, y);
}

void	dfs_weak(int x, int y)
{
	vis[x][y] = 1;
	if (board[x][y] == 'R' || board[x][y] == 'G')
		RG_dfs(x, y);
	else if (board[x][y] == 'B')
		B_dfs(x, y);	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>N;
	res = 0;
	res_weak = 0;
	for (int i = 0; i < N; i++)
		cin>>board[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == 0)
			{
				dfs(i, j);
				res++;
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			vis[i][j] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vis[i][j] == 0)
			{
				dfs_weak(i, j);
				res_weak++;
			}
		}
	}
	cout<<res<<' '<<res_weak;
	return (0);
}