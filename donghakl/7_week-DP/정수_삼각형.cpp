#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int value;
	int **arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int [n + 1];
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cin >> value;
			arr[i][0] = value;
			res = max(res, arr[i][0]); // 이부분에 대해서 생각 안했었음
			// printf("%d\n", arr[i][0]);
		}
		else
		{
			for (int j = 0; j <= i; j++)
			{
				cin >> value;
				if (j == 0)
				{
					arr[i][j] = arr[i - 1][j] + value;
				}
				else if (j > 0 && j != i)
				{
					arr[i][j] = value + max(arr[i - 1][j - 1], arr[i - 1][j]);
				}
				else if (j == i)
				{
					arr[i][j] = value + arr[i - 1][j - 1];
				}
				// printf("%d ", arr[i][j]);
				if (res < arr[i][j])
					res = arr[i][j];
			}
			// printf("\n");
		}
	}
	cout << res << "\n";
}
