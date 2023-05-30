#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;

	long sum = 0;

	cin >> n;
	vector<long> arr(n);
	vector<long> grow(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> grow[i];
	}
	sort(grow.begin(), grow.end());
	for (int i = 0; i < n; i++)
	{
		sum += (grow[i] * i);
	}
	cout << sum;
}

/*
접근법 1
매 순간 가장 큰 수를 더하면 제일 크지 않을까?
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
	{
		if (arr[i] > tmp)
		{
			tmp = arr[i];
			flag = i;
		}
	}
	result += tmp;
	arr[flag] = 0;
	for (int j = 0; j < n; j++)
	{
		arr[j] += grow[j];
	}
}

처음 제공하는 상수에 대한 이득을 얻지 못하여 최대 양을 못 구한다.
*/

/*
접근법 2
모든 수를 한 번씩 더하면서 증가률이 높은 걸 마지막에 구한다 -> 한 번 얻은걸 또 얻으면 주언 상수에 대한 이득이 없으므로
최대한 이득을 위해 증가률이 적은 순대로 더한다.
O
*/