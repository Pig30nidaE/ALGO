#include <iostream>
#include <algorithm>

using namespace std;
int n, m, k; // n->세로, m->가로
int x_1, y_1, x_2, y_2;
int depth;
int cnt = 0;

int	check_valid(int x, int y, int y_len, int x_len)
{
	if (!(x >= 0 && x < x_len))
		return (0);
	else if (!(y >= 0 && y < y_len))
		return (0);
	return (1);
}

int	DFS(int x, int y, int y_len, int x_len, int ***arr, int *depth)
{

	if ((*arr)[y][x] == 1)
		return 0;

	(*arr)[y][x] = 1;
	*depth += 1;
	if (check_valid(x + 1, y, y_len, x_len))
	{
		DFS(x + 1, y, y_len, x_len, arr, depth);
	}
	if (check_valid(x - 1, y, y_len, x_len))
	{
		DFS(x - 1, y, y_len, x_len, arr, depth);
	}
	if (check_valid(x, y + 1, y_len, x_len))
	{
		DFS(x, y + 1, y_len, x_len, arr, depth);
	}
	if (check_valid(x, y - 1, y_len, x_len))
	{
		DFS(x, y - 1, y_len, x_len, arr, depth);
	}
	return *depth;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;

	int **arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int [m];
		for (int j = 0; j < m; j++)
			arr[i][j] = 0;
	}


	for (int i = 0; i < k; i++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		for (int j = y_1; j < y_2; j++)
		{
			for (int k = x_1; k < x_2; k++)
				arr[j][k] = 1;
		}
	}	


	vector <int > result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				depth = 0;
				result.push_back(DFS(j, i, n, m, &arr, &depth));
				cnt += 1;
			}
		}
	}

	sort(result.begin(), result.end());

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
	{
		cout << result[i] << " ";
	}

	for (int i = 0; i < n; i++)
	{
		delete [] arr[i]; 
	}
	delete [] arr;
}