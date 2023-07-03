#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector <int> compressedArr;

int	binary_search(int start, int end, int to_find) {
	int mid = (start + end) / 2;
	if (mid == start) {
		if (compressedArr.at(mid) == to_find)
			return mid;
		return 0;
	}
	if (compressedArr.at(mid) < to_find)
		return binary_search(mid + 1, end, to_find);
	else if (compressedArr.at(mid) > to_find)
		return binary_search(start, mid, to_find);
	else 
		return mid;
}

int main()
{
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    unordered_set <int> num_uset;
    int n;
    cin >> n;
    int input[n];
    for (int i = 0;i < n;i++) {
        int temp;
        cin >> temp;
        if (num_uset.find(temp) == num_uset.end()) {
            num_uset.insert(temp);
            compressedArr.push_back(temp);
        }
        input[i] = temp;
    }
    sort(compressedArr.begin(), compressedArr.end());
    for (int i = 0;i < n;i++) {
        cout << binary_search(0, compressedArr.size(), input[i]) << ' ';
    }
}