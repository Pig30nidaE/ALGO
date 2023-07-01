#include <iostream>
#include <algorithm>












/////////// sort()함수 대신 힙정렬을 통해 정렬한 후 돌려보자

using namespace std;
int ft_binary_search(int target, int left, int right, int *nrr)
{
	int mid = (left + right) / 2;
	if (left > right)
		return (-1);
	if (nrr[mid] == target)
	{
		return (mid);
	}
	else if (nrr[mid] < target)
	{
		return (ft_binary_search(target, mid + 1, right, nrr));
	}
	else if (nrr[mid] > target)
	{
		return (ft_binary_search(target, left, mid - 1, nrr));
	}
	return (-1);
}

// int finder(int target, int n, vector <int > nrr)
// {
// 	int result;
// 	int cnt;
// 	int flag;

// 	cnt = 0;
// 	result = 1;
// 	result = ft_binary_search(target, 0, n - 1, nrr);
// 	if (result != -1)
// 	{
// 		cnt += 1;
// 		for (int i = result - 1; nrr[i] == target; i--)
// 		{
// 			cnt += 1;
// 		}
// 		for (int i = result + 1; nrr[i] == target; i++)
// 		{
// 			cnt += 1;
// 		}
// 	}
// 	printf("%d ", cnt);
// 	return (0);
// }

int finder(int target, int n, int *nrr)
{
	int result;
	int cnt;
	int flag;

	cnt = 0;
	result = ft_binary_search(target, 0, n - 1, nrr);
	if (result != -1)
	{
		if (nrr[0] == nrr[n - 1])
		{
			return (n);
		}
		cnt += 1;
		for (int i = result - 1; nrr[i] == target; i--)
		{
			cnt += 1;
		}
		for (int i = result + 1; nrr[i] == target; i++)
		{
			cnt += 1;
		}
	}
	return (cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, tmp, cnt = 0, j;
	cin >> n;
	int *nrr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> nrr[i];
	}

	sort(nrr, nrr + n);

	int result;
	int res;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> result;
		printf("%d ", finder(result, n, nrr));
	}
	printf("\n");
}