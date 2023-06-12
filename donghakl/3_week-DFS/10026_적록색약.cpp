#include <iostream>
#include <algorithm>

using namespace std;
// depth[R, B, G, 깊이]

int *dfs(int x, int y, int arr[101][101], int visit[101][101], int depth[], int map_len, int target, int flag)
{
	if (x < 0 || x >= map_len || y < 0 || y >= map_len)
	{
		return (0);
	}
	else if (visit[y][x] != 0)
		return (0);
	else if (depth[3] != 0 && target != arr[y][x])
	{
		if (!(flag == 1 && ((target == 'G' || target== 'R') && (arr[y][x] == 'G' || arr[y][x] == 'R'))))
			return (0);
	}
	
	visit[y][x] = 1;

	if (arr[y][x] == 'R')
		depth[0] += 1;
	else if (arr[y][x] == 'B')
		depth [1] += 1;
	else if (arr[y][x] == 'G')
		depth [2] += 1;
	depth[3] += 1;
	dfs(x + 1, y, arr, visit, depth, map_len, arr[y][x], flag);
	dfs(x - 1, y, arr, visit, depth, map_len, arr[y][x], flag);
	dfs(x, y + 1, arr, visit, depth, map_len, arr[y][x], flag);
	dfs(x, y - 1, arr, visit, depth, map_len, arr[y][x], flag);
	return (depth);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[101][101] = {0, };
	int visit1[101][101] = {0, };
	int visit2[101][101] = {0, };
	int depth[4] = {0, };
	string color;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> color;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = color[j];
		}
	}

	int *result;
	int first = 0, second = 0;

	for(int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit1[i][j] == 0)
			{
		 		result = dfs(j, i, arr, visit1, depth, n, 0, 0);
				if (result[3] != 0)
					first++;
				for (int k = 0; k < 4; k++)
					depth[k] = 0;
			}
			if (visit2[i][j] == 0)
			{
		 		result = dfs(j, i, arr, visit2, depth, n, 0, 1);
				if (result[3] != 0)
					second++;
				for (int k = 0; k < 4; k++)
					depth[k] = 0;
			}
		}
	}
	cout << first << " " << second << "\n";


	// printf("\n");
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
}