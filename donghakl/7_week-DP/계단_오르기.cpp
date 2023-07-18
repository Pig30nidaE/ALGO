#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 4, value;
	cin >> n;
	int *arr = new int[n + 1];
	int *dp = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(dp[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n] << "\n";
}