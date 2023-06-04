#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void move_hunter(int x, int y, int arr_x_len, int arr_y_len, vector<std::vector<int> > *arr, queue<pair<int, int> > *que)
{
	if ((y < arr_y_len) && (y >= 0) && (x < arr_x_len) && (x >= 0))
	{
		if ((*arr)[y][x] == 1)
		{
			(*arr)[y][x] = 0;
			(*que).push(make_pair(y, x));
		}
	}
}

void bfs(queue<pair<int, int> > *que, vector<std::vector<int> > *arr, int arr_y_len, int arr_x_len)
{
	int que_size;
	int x, y;

	while (1)
	{
		if ((*que).empty())
			return ;
		que_size = (*que).size();
		for (int i = 0; i < que_size; i++)
		{
			x = (*que).front().second;
			y = (*que).front().first;
			move_hunter(x, y + 1, arr_x_len, arr_y_len, arr, que);
			move_hunter(x, y - 1, arr_x_len, arr_y_len, arr, que);
			move_hunter(x + 1, y, arr_x_len, arr_y_len, arr, que);
			move_hunter(x - 1, y, arr_x_len, arr_y_len, arr, que);
			(*que).pop();
		}
	}
}

void get_hunter_cnt(queue<pair<int, int> > que, vector<std::vector<int> > arr, int arr_y_len, int arr_x_len)
{
	int cnt = 0;

	for (int i = 0; i < arr_y_len; i++)
	{
		for (int j = 0; j < arr_x_len; j++)
		{
			if (arr[i][j] == 1)
			{
				// for(int z = 0; z < arr_y_len; z++)
				// {
				// 	for (int v = 0; v < arr_x_len; v++)
				// 	{
				// 		printf("%d", arr[z][v]);
				// 	}
				// 	printf("\n");
				// }
				// printf("\n");
				// printf("\n");
				cnt++;
				arr[i][j] = 0;
				que.push(make_pair(i, j));
				bfs(&que, &arr, arr_y_len, arr_x_len);
			}
		}
	}
	printf("%d\n", cnt);
}

// int **get_array(int x, int y)
// {
// 	int **arr;

// 	arr = (int **)malloc(sizeof(int *) * y);
// 	for (int i = 0; i < y; i++) // int배열 세팅
// 	{
// 		arr[i] = (int *)malloc(sizeof(int) * x);
// 		for(int j = 0; j < x; j++) // int배열 0으로 초기화
// 		{
// 			arr[i][j] = 0;
// 		}
// 	}
// 	return (arr);
// }

int main()
{
	int t;
	int n, m; // n-세로, m-가로
	int hunter;
	int x, y;

	queue<pair<int, int> > que;
	
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> hunter;

		vector<std::vector<int> > arr(n, std::vector<int>(m, 0));

		for (int i = 0; i < hunter; i++)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}
		
		get_hunter_cnt(que, arr, n, m);



		

		// for(int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		printf("%d", arr[i][j]);
		// 	}
		// 	printf("\n");
		// }
		// printf("\n");
		// printf("\n");

	}
	return (0);
}