#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int check_finish(int **arr, int max_y, int max_x)
{
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (arr[i][j] == 1)
				return (1);
		}
	}
	return (0);
}

int bfs_checker_push(int x, int y, int arr_y_len, int arr_x_len, int ***arr, queue<pair<int, int> > *que)
{
	if (((y < arr_y_len && y >= 0) && (x < arr_x_len && x >= 0)))
	{
		if ((*arr)[y][x] == 1)
		{
			(*arr)[y][x] = -1;
			(*que).push(make_pair(y, x));
			// printf("y:%d, x:%d 간드아!!\n", y, x);
			return (1);
		}
	}
	return (0);
}

int bfs(queue<pair<int, int> > que, int ***arr, int arr_y_len, int arr_x_len)
{
	int x, y;
	int cnt = 1;
	int que_size;

	while (1)
	{
		if (que.empty())
			return (cnt);
		que_size = que.size();
		// printf("que size:%d\n", que_size);
		for(int i = 0; i < que_size; i++)
		{
			y = que.front().first;
			x = que.front().second;
			cnt += bfs_checker_push(x, y+1, arr_y_len, arr_x_len, arr, &que);
			cnt += bfs_checker_push(x, y-1, arr_y_len, arr_x_len, arr, &que);
			cnt += bfs_checker_push(x+1, y, arr_y_len, arr_x_len, arr, &que);
			cnt += bfs_checker_push(x-1, y, arr_y_len, arr_x_len, arr, &que);
			que.pop();
		}
		// printf("cnt : %d\n", cnt);
	}
	return (cnt);
}

void get_draw(queue<pair<int, int> > que, int **arr, int arr_y_len, int arr_x_len)
{
	int cnt = 0;
	int big = 0;
	int tmp = 0;

	for (int i = 0; i < arr_y_len; i++)
	{
		for (int j = 0; j < arr_x_len; j++)
		{
			if (arr[i][j] == 1)
			{
				arr[i][j] = -1;
				que.push(make_pair(i, j));
				// printf("que y:%d, x:%d\n", i, j);
				cnt++;
				tmp = bfs(que, &arr, arr_y_len, arr_x_len);
				que.pop();
				// printf("num:%d, size:%d\n", cnt, tmp);
				if(big < tmp)
				{
					big = tmp;
				}
			}

		}
	}
	printf("%d\n", cnt);
	printf("%d\n", big);
}

int main() // 입장한 곳은 '-1';
{
	int n, m; // n - 세로, m - 가로
	int **arr;
	queue <pair<int, int> > que;

	cin >> n >> m;
	arr = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * m);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	get_draw(que, arr, n, m);

	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
}