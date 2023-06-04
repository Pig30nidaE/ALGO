#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int check_finish(pair<int, int > finish, int **arr)
{
	if (arr[finish.first][finish.second] == 0)
		return (0);
	else
		return (1);
}

void bfs_checker_push(int x, int y, int arr_y_len, int arr_x_len, int ***arr, queue<pair<int, int> > *que)
{
	if (((y < arr_y_len && y >= 0) && (x < arr_x_len && x >= 0)))
	{
		if ((*arr)[y][x] == 1)
		{
			(*arr)[y][x] = 0;
			(*que).push(make_pair(y, x));
		}
	}
}

int bfs(queue<pair<int, int> > que, pair<int, int > finish, int **arr, int arr_y_len, int arr_x_len)
{
	int x, y;
	int cnt = 1;
	int que_size;

	while (check_finish(finish, arr))
	{
		que_size = que.size();
		for(int i = 0; i < que_size; i++)
		{
			y = que.front().first;
			x = que.front().second;
			bfs_checker_push(x, y+1, arr_y_len, arr_x_len, &arr, &que);
			bfs_checker_push(x, y-1, arr_y_len, arr_x_len, &arr, &que);
			bfs_checker_push(x+1, y, arr_y_len, arr_x_len, &arr, &que);
			bfs_checker_push(x-1, y, arr_y_len, arr_x_len, &arr, &que);
			que.pop();
		}
		cnt ++;
	}
	return (cnt);
}

int main()
{
	int n, m; // n - 세로, m - 가로
	string line;
	pair<int, int > finish;
	queue<pair<int, int> >que;

	que.push(make_pair(0, 0));
	cin >> n >> m;
	finish = make_pair(n - 1,m - 1); // 도착지점 설정
	int **arr = (int **)malloc(sizeof(int *) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(sizeof(int) * m);
	}

	for (int i = 0; i < n; i++)
	{
		cin >> line;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = line[j] - '0';
		}
	}

	printf("%d\n", bfs(que, finish, arr, n, m));
	
	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return (0);
}