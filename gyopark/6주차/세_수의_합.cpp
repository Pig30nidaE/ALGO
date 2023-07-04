#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

// 2295

int N;
vector<int> two;

bool bi_search(int low, int len, int target)
{
	int high = len - 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (target == two[mid])	{ return true; }
		if (two[mid] < target) { low = mid + 1; }
		else if (two[mid] > target) { high = mid - 1; }
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;
	
	int arr[1005];
	
	for (int i = 0; i < N; i++) 
		cin>>arr[i];
	
	sort(arr, arr + N);
	
	for (int i = 0; i < N; i++) 
		for (int j = i; j < N; j++)
			two.push_back(arr[i] + arr[j]);
	
	sort(two.begin(), two.end());
	
	int result = 0;
	
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (bi_search(0, two.size(), arr[j] - arr[i]))
				result = max(result, arr[j]);

	cout<<result;
	return 0;
}
// 1 2 3 6 15
// 1 10 10 10 30
// a1 + a2 + a3 = a4 
// -> a4 - a3 = a1 + a2