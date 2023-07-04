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

int main()
{
    std::ios::sync_with_stdio(0);std::cin.tie(0);
    cin >> N;
    
    for (int i = 0; i < N; i++) { int num; cin>>num; a.push_back(num); };
    vector<int> b(a);
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for (int i = 0; i < b.size(); i++)
    std::cout << std::lower_bound(a.begin(), a.end(), b[i]) - a.begin() << ' ';

    return 0;
}