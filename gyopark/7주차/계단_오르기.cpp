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

//2579

int stair[303];
int dp[303];
int n;

//0
//10 20
//

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    stair[0] = 0;
    for (int i = 0; i < n; i++)
        cin>>stair[i];
    dp[0] = stair[0];
    dp[1] = stair[0] + stair[1];
    dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i = 3; i < n; i++)
        dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
    cout<<dp[n - 1];
    return 0;
}