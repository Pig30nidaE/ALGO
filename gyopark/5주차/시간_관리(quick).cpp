#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

//1263

int	T, ans;

void	QuickSort(vector<pair<int, int> > &arr, int start, int end)
{
	if (start >= end) { return; }
	// 배열의 size가 하나일 경우 그냥 반환

	int left = start - 1;
	int right = end + 1;
	int	mid = arr[(left + right) / 2].first;
	
	while (1)
	{
		while (arr[++left].first < mid)
			;
		while (arr[--right].first > mid)
			;
		if (left >= right)
			break ;
		swap(arr[left], arr[right]);
	}
	QuickSort(arr, start, left - 1);
	QuickSort(arr, right + 1, end);
	//분할 정복을 사용하여 O(nlogn)으로 빠르게 정렬가능
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>T;

	vector<pair<int, int> > ts;
	for (int i = 0; i < T; i++)
	{
		int t, s;
		cin>>t>>s;
		ts.push_back(make_pair(s, t));
	}
	
	int size = ts.size();
	QuickSort(ts, 0, size - 1);

	ans = ts[T - 1].first;

	for (int idx = T - 1; idx >= 0; idx--)
	{
		ans -= ts[idx].second;
		if (ans >= ts[idx - 1].first)
			ans = ts[idx - 1].first;
	}
	if (ans < 0)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}

//3 5   5  3
//8 14  14 8
//1 16  16 1
//5 20  20 5
