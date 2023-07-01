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

//10816

int N, M;
map<int, int> m;
vector<int> c;
vector<int> f;

void    bi_search(int target)
{
	int low = 0;
	int high = c.size() - 1;
	
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (c[mid] == target) { cout<<m[target]<<' '; return ;}
		if (c[mid] > target) { high = mid - 1; }
		else if (c[mid] < target) { low = mid + 1; }
	}
	cout<<0<<' ';
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N;

	for (int i = 0; i < N; i++)
	{
		int num; cin>>num; c.push_back(num); m[num]++;
	}

	cin>>M;
	for (int i = 0; i < M; i++)
	{
		int num; cin>>num; f.push_back(num);
	}

	sort(c.begin(), c.end());
	
	for (int i = 0; i < M; i++)
		bi_search(f[i]);
	return 0;
}