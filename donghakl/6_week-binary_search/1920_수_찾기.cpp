#include <iostream>
#include <algorithm>

using namespace std;

int ft_binary_search(int *arr, int target, int left, int right)
{
	int mid = (left + right) / 2;

	if (left > right)
		return (0);
	if (arr[mid] == target)
		return (1);
	else if (arr[mid] < target)
		return (ft_binary_search(arr, target, mid + 1, right));
	else if (arr[mid] > target)
		return (ft_binary_search(arr, target, left, mid - 1));
	return (0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int target;

	cin >> n;
	int *nrr;
	nrr = new int[n]();
	for (int i = 0; i < n; i++)
		cin >> nrr[i];

	sort(nrr, nrr + n);
	cin >> m;
	int *mrr;
	mrr = new int[m]();
	for (int i = 0; i < m; i++)
		cin >> mrr[i];

	if (n > 2)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d\n", ft_binary_search(nrr, mrr[i], 0, n - 1));
		}
	}
	else if (n == 2) // 이진 탐색은 반씩 쪼개야되는데 3개 미만부터는 무의미해진다
	{
		int flag;
		for(int i = 0; i < m; i++)
		{
			flag = 0;
			for (int j = 0; j < n; j++)
			{
				if (mrr[i] == nrr[j])
				{
					flag = 1;
				}
			}
		if (flag == 1)
			printf("1\n");
		else
			printf("0\n");
		}
	}
	else if (n == 1)
	{
		for (int i = 0; i < m; i++)
		{
			if (mrr[i] == nrr[0])
				printf("1\n");
			else
				printf("0\n");
		}
	}

}