#include <iostream>
#include <algorithm>

using namespace std;

int dfs(int x, int y, int arr[101][101], int visit[101][101], int *depth, int water, int map_len)
{
	// cout << "current: " << x << ", " << y << "\n";
	if (x < 0 || map_len <= x || y < 0 || map_len <= y)
		return (0);
	if (visit[y][x] != 0)
		return (0);
	else if (arr[y][x] <= water)
		return (0);
	// cout << "current: " << x << ", " << y << "\n";
	visit[y][x] = 1;
	*depth += 1;
	dfs(x + 1, y, arr, visit, depth, water, map_len);
	dfs(x - 1, y, arr, visit, depth, water, map_len);
	dfs(x, y + 1, arr, visit, depth, water, map_len);
	dfs(x, y - 1, arr, visit, depth, water, map_len);
	return (*depth);
}

int get_max_safe(int arr[101][101], int visit[101][101], int map_len, int water_min, int water_max)
{
	int max = 1; // water높이가 0일때 안전영역이 1이니까, 최소 1부터 시작한다.
	int cnt;
	int tmp = 0;
	int depth = 0;

	
	while (water_min < water_max)
	{
		cnt = 0;
		for (int i = 0; i < map_len; i++)
		{
			for (int j = 0; j < map_len; j++)
			{
				// cout << j << ", " << i << ": " << visit[i][j] << "\n";
				if (visit[i][j] == 0)
				{
					tmp = dfs(j, i, arr, visit, &depth, water_min, map_len);
					if (tmp)
						cnt++;
					depth = 0;
				}
			}
		}
		for (int i = 0; i < map_len; i++)
		{
			for (int j = 0; j < map_len; j++)
			{
				visit[i][j] = 0;
			}
		}
		if (cnt > max)
			max = cnt;
		water_min++;
	}
	cout << max << "\n";
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int visit[101][101] = {0, };
	int arr[101][101] = {0, };
	int water;
	int min_tmp;
	int max_tmp;
	int water_min = 100;
	int water_max = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> water;
			min_tmp = water;
			max_tmp = water;
			if (min_tmp < water_min)
				water_min = min_tmp;
			if (max_tmp > water_max)
				water_max = max_tmp;
			arr[i][j] = water;
		}
	}

	get_max_safe(arr, visit, n, water_min, water_max);


	// cout << "\n";
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < n; j++)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";
}