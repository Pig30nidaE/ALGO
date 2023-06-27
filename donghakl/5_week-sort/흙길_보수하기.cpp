#include <iostream>
#include <algorithm>

using namespace std;


void quick_sort(vector <pair <int, int > > *vec, int start, int end)
{
	int left = start;
	int right = end;
	int pivot = (*vec)[(start + end) / 2].first;
	
	while (left <= right)
	{
		while (((*vec)[left].first < pivot))
			left++;
		while (((*vec)[right].first > pivot))
			right--;
		if (left <= right)
		{
			swap((*vec)[left], (*vec)[right]);
			left++;
			right--;
		}
	}
	if (start < right)
		quick_sort(vec, start, right);
	if (left < end)
		quick_sort(vec, left, end);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	int fir, sec;

	cin >> n >> l;
	vector <pair <int, int > > vec;
	for (int i = 0; i < n; i++)
	{
		cin >> fir >> sec;
		vec.push_back(make_pair(fir, sec));
	}

	quick_sort(&vec, 0, n - 1);

	int end = 0;
	int size;
	int cnt;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (vec[i].first <= end)
			vec[i].first = end + 1;
		if (vec[i].first >= vec[i].second)
			continue;
		size = vec[i].second - vec[i].first;
		for (cnt = 1; cnt * l < size; cnt++);

		end = vec[i].first + (cnt * l) - 1;
		result += cnt;
	}
	cout << result << "\n";
}