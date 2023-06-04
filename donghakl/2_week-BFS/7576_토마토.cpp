#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int	finish_check(int **arr, int arr_x_len, int arr_y_len)
{
	int n, m;

	n = arr_y_len;
	m = arr_x_len;

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
				return (1);
		}
	}
	return (0);
}

int	go_bfs(int **arr, int arr_x_len, int arr_y_len, queue<pair<int, int> >bfs)
{
	int cnt = 0;
	int queue_size;	
	int x, y;
	while (finish_check(arr, arr_x_len, arr_y_len))
	{
		if (bfs.empty())
			return (-1);
		queue_size = bfs.size();
		for(int i = 0; i < queue_size; i++)
		{
				y = bfs.front().first;
				x = bfs.front().second;
				if (((y + 1 < arr_y_len && y + 1 >= 0) && (x < arr_x_len && x >= 0)))
				{
					if (arr[y+1][x] == 0)
					{
					arr[y+1][x] = 1;
					bfs.push(make_pair(y + 1, x));
					}
				}
				if (((y - 1 < arr_y_len && y - 1 >= 0) && (x < arr_x_len && x >= 0)))
				{
					if (arr[y-1][x] == 0)
					{
					arr[y - 1][x] = 1;
					bfs.push(make_pair(y - 1, x));
					}
				}
				if (((y < arr_y_len && y >= 0) && (x + 1 < arr_x_len && x + 1 >= 0)))
				{
					if (arr[y][x+1] == 0)
					{
					arr[y][x + 1] = 1;
					bfs.push(make_pair(y, x + 1));
					}
				}
				if (((y < arr_y_len && y >= 0) && (x - 1 < arr_x_len && x - 1 >= 0)))
				{
					if (arr[y][x-1] == 0)
					{
					arr[y][x - 1] = 1;
					bfs.push(make_pair(y, x - 1));
					}
				}
			bfs.pop();
		}
		cnt ++;
	}
	return (cnt);
}

int main()
{
	int n, m; //n:가로, m:세로
	int	start_cnt = 0;

	cin >> n >> m;

	int **arr = (int **)malloc(sizeof(int *) * m);

	for (int i = 0; i < m; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				start_cnt += 1;
		}
	}

	queue<pair<int, int> >bfs;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
		bfs.push(make_pair(i, j));
			}
		}
	}
	printf("%d\n", go_bfs(arr, n, m, bfs));
	for (int i = 0; i < m; i++)
	{
		free(arr[i]);
	}
	free(arr);
}