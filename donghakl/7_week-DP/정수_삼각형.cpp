#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int all = ((2 + (n -1 -1) * 1) * (n - 1)) / 2;
	vector <int > arr[all];
	for (int i = 1; i < n; i++)
	{
		if (i % 3 == 0)
		{
			arr[i] = 1;
		}
	 	else if (i)
		{

		}
		else if (i)
	}
	cout << n;
}
