#include <algorithm>
#include <iostream>
using namespace std;

int	recur(int n, int count) {
	if (n == 1)
		return count;
	if (n == 2)
		return count + 1;
	int	divide3 = n;
	int divide2 = n;
	int	count3 = count;
	int	count2 = count;
	while (divide3 >= 3 && divide3 % 3) {
		divide3--;
		count3++;
	}
	while (divide2 >= 2 && divide2 % 2) {
		divide2--;
		count2++;
	}
	divide3 = recur(divide3 / 3, count3 + 1);
	divide2 = recur(divide2 / 2, count2 + 1);
	if (divide3 < divide2)
		return divide3;
	else
		return divide2;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	long long	n;
	int	count;

	count = 0;
	cin >> n;
	cout << recur(n, count);
}