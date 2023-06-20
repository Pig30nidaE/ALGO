#include <iostream>
#include <algorithm>

using namespace std;

int n_arr[20001] = {0, };
int m_arr[20001] = {0, };

int insert_sort_find_target(int arr[], int size, int target)
{
	int j;
	for (j = size - 1; j >= 0 && arr[j] >= target; j--);
	return j+1;
}

void insert_sort(int arr[], int size)
{
	int key, j, i;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int n, m;
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> n_arr[i];
		}

		for (int i = 0; i < m; i++)
		{
			cin >> m_arr[i];
		}
		insert_sort(m_arr, m);

		int key = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			key = n_arr[i];
			cnt += insert_sort_find_target(m_arr, m, key);
		}
		cout << cnt << "\n";



	}
}	