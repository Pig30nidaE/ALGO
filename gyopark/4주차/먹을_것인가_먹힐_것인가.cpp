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

// 7795

int N;
int x, y;

int lowerBound(int a, vector<int>B)
{
    int sum = 0;
    int l = 0;
    int r = B.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a > B[mid])
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void    solve()
{
    int x, y;
    cin>>x>>y;

    vector<int> A(x);
    for (int i = 0; i < x; i++)
        cin>>A[i];

    vector<int> B(y);
    for (int i = 0; i < y; i++)
        cin>>B[i];

    sort(A.begin(), A.end()); 
    sort(B.begin(), B.end());
    
    int sum = 0;
    for (int i = 0; i < A.size(); i++)
        sum += lowerBound(A[i], B);

    cout<<sum<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>N;
    while (N--)
        solve();

    return 0;
}