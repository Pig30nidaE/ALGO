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

// 1463
int d[1010101];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0) d[i] = min(d[i], d[i / 2] + 1);
        if (i % 3 == 0) d[i] = min(d[i], d[i / 3] + 1);
    }
    cout<<d[n];
    return 0;
}