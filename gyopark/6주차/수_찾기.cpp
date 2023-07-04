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

// 1920

int	N, M;
vector<int>	A;
vector<int>	C;

void	bin_search(int low, int high, int target)	// using while loop
{
	while (low <= high)
	{
		int	mid = (low + high) / 2;
		if (target == A[mid]) { cout << 1 << '\n'; return; }
		if (target < A[mid]) { high = mid - 1; }
		else if (target > A[mid]) { low = mid + 1; }
	}
	cout << 0 << '\n';
}

// void	bin_search_cur(int low, int high, int target)
// {
// 	if (low > high)	{ cout << 0 << '\n'; return; }
// 	int	mid = (low + high) / 2;
// 	if (A[mid] == target)	{ cout << 1 << '\n'; return; }
// 	if (A[mid] > target)
// 		return (bin_search_cur(low, mid - 1, target));
// 	else
// 		return (bin_search_cur(mid + 1, high, target));
// }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int	num;
		cin >> num;
		A.push_back(num);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int	num;
		cin >> num;
		C.push_back(num);
	}

	sort(A.begin(), A.end());
	int	len = A.size();
	for (int i = 0; i < M; i++)
		bin_search(0, len - 1, C[i]);
		// bin_search_cur(0, len - 1, C[i]);

	return 0;
}
