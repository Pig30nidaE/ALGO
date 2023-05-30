#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x)  (x).begin(), (x).end()
#define rep(i, a, b) for(int i=(a);i<(b);++i)
using namespace std;

long long res;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N;
    int tree;
    cin>>N;
    vector<int>grow(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tree;
        res += tree;
    }
    for (int i = 0; i < N; i++)
        cin >> grow[i];
    sort(grow.begin(), grow.end());
    for (int i = 0; i < N; i++)
    {    
        res += grow[i] * (i);
    }
    cout<<res;
}
