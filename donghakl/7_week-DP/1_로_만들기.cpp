#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	if (n < 4)
	{
		cout << "1\n";
		return (0);
	}
	int *arr = new int[n + 1]();
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


5 7 8 8 7 5