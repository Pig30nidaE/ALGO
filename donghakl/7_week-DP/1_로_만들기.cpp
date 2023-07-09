#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int *arr = new int[n + 1]();
	for (int i = 2; i <= n; i++)
	{
		// if (i % 2 == 0)
		// {
		// 	arr[i] = min(arr[i / 2] + 1, arr[i - 1] + 1);
		// }
		// else if (i % 3 == 0)
		// {
		// 	arr[i] = min(arr[i / 3] + 1, arr[i - 1] + 1);
		// }
		// else

		/*
		-위에가 틀린 이유-
		1. i 가 6의 배수일 때위에서 "if (i % 2)"가 참이되면 밑의 "else if (i % 3)"가 실행이 안된다.
		2. "i % 2", "i % 3" 부분을 각각의 if문으로 하여도 min 부분에서 "arr[i - 1] + 1" 부분에서
		이전 비교문에 독립된 상태로 "arr[i - 1] + 1"과 비교하기 때문에 올바르지 못하다.

		=> 기본적으로 arr[i]을 arr[i - 1] + 1로 초기화 하고 모든 경우에 대해서 비교하여 최소값을 가지도록 고쳐준다.
		*/

		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
		{
			arr[i] = min(arr[i / 2] + 1, arr[i]);
		}
		if (i % 3 == 0)
		{
			arr[i] = min(arr[i / 3] + 1, arr[i]);
		}
	}
	cout << arr[n] << "\n";
}