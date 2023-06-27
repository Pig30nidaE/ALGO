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

int	board[51][51] = 
    {{1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
     {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool vis[51][51];
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int	dy[4] = {0, 1, 0, -1};

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({0, 0});
	while (!Q.empty())
	{
		
	}
}

