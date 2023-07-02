#include <iostream>
#include <algorithm>

using namespace std;

int cmp(int text1, int text2)
{
	if (text1 < text2)
		return 1;
	else if (text1 > text2)
		return 2;
	else
		return 0;
}

void makeheap(int *vec, int root, int n)
{
	int temp;
	int temp_fir = vec[root];
	int child = root * 2;
	while (child <= n)
	{
		if (child < n && cmp(vec[child], vec[child + 1]) == 1)
			child++;
		if (cmp(temp_fir, vec[child]) == 1)
		{
			swap(vec[child/2], vec[child]);
			child *= 2;
		}
		else
			break;
	}
	vec[child/2] = temp_fir;
}

void heapsort(int *vec, int n)
{
	int temp;
	for (int i = n/2; i > 0; i--)
		makeheap(vec, i, n);

	for (int i =n; i > 0; i--)
	{
		swap(vec[1], vec[i]);
		makeheap(vec, 1, i - 1);
	}
}

int ft_lower_bound(int target, int left, int right, int *nrr)
{
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (nrr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (right);
}

int ft_upper_bound(int target, int left, int right, int *nrr)
{
	int mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (nrr[mid] <= target)
			left = mid + 1;
		else
			right = mid;
	}
	return (right);
}

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

int finder(int target, int n, int *nrr)
{
	int lower;
	int upper;

	lower = ft_lower_bound(target, 1, n, nrr);
	upper = ft_upper_bound(target, 1, n, nrr);
	
	if (lower == upper)
		printf("0 ");
	else
		printf("%d ", upper - lower);
	// result = ft_binary_search(target, 1, n - 1, nrr);
	// if (result != -1)
	// {
	// 	if (nrr[0] == nrr[n - 1])
	// 	{
	// 		return (n);
	// 	}
	// 	cnt += 1;
	// 	for (int i = result - 1; nrr[i] == target; i--)
	// 	{
	// 		cnt += 1;
	// 	}
	// 	for (int i = result + 1; nrr[i] == target; i++)
	// 	{
	// 		cnt += 1;
	// 	}
	// }
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, tmp, cnt = 0, j;
	cin >> n;
	int *nrr = new int[n + 1]();

	for (int i = 1; i < n + 1; i++)
	{
		cin >> nrr[i];
	}

	heapsort(nrr, n);

	int result;
	int res;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> result;
		finder(result, n + 1, nrr);
		// printf("%d ", finder(result, n + 1, nrr));
	}
}