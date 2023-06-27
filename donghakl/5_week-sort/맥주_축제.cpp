#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


// void dfs(int n, int m, int k, int idx, int cnt, int result, vector <pair <int, int > > vec, int *flag, vector <int> stack)
// { //vec는  선선호호도  오오름름차차순순

// 	if (idx >= k)
// 		return;
// 	// printf("%d:알콜:%d, 선호도:%d\n", idx, vec[idx].first, vec[idx].second);
// 	stack.push_back(vec[idx].second);
// 	result += vec[idx].second;
// 	cnt += 1;
// 	sort(stack.begin(), stack.end());
// 	if (cnt > n)
// 	{
// 		result -= stack[0];
// 		stack.erase(stack.begin());
// 		cnt -= 1;
// 	}
// 	if (cnt == n && result >= m)
// 	{
// 		*flag = 1;
// 		printf("%d\n", vec[idx].first);
// 		return ;
// 	}
// 	dfs(n, m, k, idx + 1, cnt, result, vec, flag, stack);
// }
struct cmp {
  bool operator()(int a, int b) {
    return a > b;
  }
};

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

	int n, m, k, v, c, flag = 0;
	cin >> n >> m >> k;

	vector <pair <int, int > > vec;
	for (int i = 0; i < k; i++)
	{
		cin >> v >> c;
		vec.push_back(make_pair(c, v));
	}

	// sort(vec.begin(), vec.end());
	quick_sort(&vec, 0, k - 1);

	 priority_queue<int, vector<int>, cmp> stack;

	int cnt = 0, result = 0;
	for (int i = 0; i < k; i++)
	{
		stack.push(vec[i].second);
		result += vec[i].second;
		cnt += 1;
		if (cnt > n)
		{
			result -= stack.top();
			stack.pop();
			cnt -= 1;
		}
		if (cnt == n && result >= m)
		{
			printf("%d\n", vec[i].first);
			return (0);
		}
	}
	printf("-1\n");
}