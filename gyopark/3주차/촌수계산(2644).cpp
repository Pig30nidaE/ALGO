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

int     board[102][102];
int     vis[102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, a, b, m, x, y;
int	ans = -1;

// 그래프 이론
void	dfs(int i, int depth)
{
	vis[i] = 1;
	++depth;
	if (i == b) {
		ans = depth;
		return;
	}
	for (int k = 1; k <= n; k++)
	{
		if (vis[k] == 1)
			continue;
		if (board[i][k] == 0)
			continue;
		dfs(k, depth);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	cin>>a>>b;
	cin>>m;
	while (m--)
	{
		cin>>x>>y;
		board[x][y] = 1;
		board[y][x] = 1;
	}
	dfs(a, -1);
	if (ans == 0)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}

//          1        4
//        2   3    5   6
//      7 8 9
// https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2Fbx8K9G%2FbtqGK4veRmL%2FaP87rF6Jis9hnmZh6rpGK1%2Fimg.png