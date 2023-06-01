#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int	finish_check(vector<vector<int> >arr)
{
	int n, m;

	n = arr.size();
	m = arr[0].size();

	for (int i = 0; i < n; i++)
	{
		if (find(begin(arr[i]), end(arr[i]), 0) != end(arr[i]))
		{
			return (1);
		}
	}
	return (0);
}

void	go_bfs(vector<vector<int> > arr, int size, vector<pair<int, int> >vec, queue<pair<int, int> >bfs)
{
	int queue_size;	
	int x, y;
	while (finish_check(arr))
	{
		queue_size = bfs.size();
		for(int i = 0; i < queue_size; i++)
		{
			if (bfs.empty())
			{
				printf("bfs.empty!\n");
				return ;
			}
			else
			{
				bfs.push(make_pair(bfs.front().first + 1, bfs.front().second));
				bfs.push(make_pair(bfs.front().first + -1, bfs.front().second));
				bfs.push(make_pair(bfs.front().first, bfs.front().second + 1));
				bfs.push(make_pair(bfs.front().first, bfs.front().second - 1));
				bfs.pop();
			}
		}
		printf("hello\n");
		queue_size = bfs.size();
		for (int i = 0; i < queue_size; i++)
		{
			x = bfs.front().first;
			y = bfs.front().second;
			if ((x >= arr.size()) || (y >= arr[0].size()))
			{
				continue;
			}
			if (arr[x][y] != 0)
				continue;
			arr[x][y] = 1;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			for (int j = 0; j < arr[0].size(); j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");

	}
}

int main()
{
	int n, m; //n:가로, m:세로
	int	start_cnt = 0;

	cin >> n >> m;

	vector<vector<int> > arr(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				start_cnt += 1;
		}
	}

	vector<pair<int, int> > vec;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				vec.push_back(make_pair(i, j));
			}
		}
	}
	queue<pair<int, int> >bfs;
	for (int i = 0; i < vec.size(); i++)
	{
		bfs.push(make_pair(vec[i].first, vec[i].second));
	}
	go_bfs(arr, start_cnt, vec, bfs);


	// tester
	// for (int i = 0; i < vec.size(); i++)
	// {
	// 	bfs.push(make_pair(vec[i].first, vec[i].second));
	// 	printf("%d,%d\n", bfs.front().first, bfs.front().second);
	// 	bfs.pop();
	// }
	// printf("%ld\n", vec.size());

	// for (int i = 0; i < vec.size(); i++)
	// {
	// 	cout << vec[i].first << vec[i].second;
	// }
	// printf("\n\n");
}