#include <algorithm>
#include <iostream>
using namespace std;

int	binary_search(int start, int end, int *A, int to_find) {
	if (start > end)
		return -1;
	int mid = (start + end) / 2;
	if (A[mid] < to_find)
		return binary_search(mid + 1, end, A, to_find);
	else if (A[mid] > to_find)
		return binary_search(start, mid - 1, A, to_find);
	else
		return mid;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	int n;
	cin >> n;

	int A[n];
	for (int i = 0;i < n;i++)
		cin >> A[i];
	sort(A, A + n);
	int m;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int to_find;
		cin >> to_find;
		if (binary_search(0, n - 1, A, to_find) >= 0)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}