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

int N;
vector<int> a;

// a -10(0) -9(1) 2(2) 4(3)
// b 2 4 -10 4 -9

int bi_search(int target)
{
    int low = 0;
    int high = a.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == target) { return mid; }
        if (a[mid] < target) { low = mid + 1; }
        else if (a[mid] > target) { high = mid - 1; }
    }
    return (0);
}

int main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) { int num; cin>>num; a.push_back(num); };
    vector<int> b(a);
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for (int i = 0; i < b.size(); i++)
        std::cout << bi_search(b[i]) << ' ';

    return 0;
}