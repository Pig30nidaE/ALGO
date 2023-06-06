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

int 	board[502][502];
bool    vis[502][502];
int 	r,c,res,area;
int 	tmp_area = 0;
int 	dx[4] = {1, 0, -1, 0};
int 	dy[4] = {0, 1, 0, -1};

void	bfs(int i, int j)
{
    tmp_area = 0;
	queue<pair<int, int>> q;
	vis[i][j] = true;
	q.push({i, j});
	while (!q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();
        tmp_area++;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (board[nx][ny] != 1 || vis[nx][ny])
				continue;
			vis[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>r>>c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin>>board[i][j];

	int res = 0;
	int	area = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int num = 0;
			if (board[i][j] == 1 && !vis[i][j])
			{
				res++;
				bfs(i, j);
                if (tmp_area > area)
                    area = tmp_area;
			}
		}
	}
	cout<<res<<'\n'<<area;    
	return 0;
}