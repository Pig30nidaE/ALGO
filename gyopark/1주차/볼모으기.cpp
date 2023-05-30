#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define int long long
using namespace std;
// using vi = vector<int>;

int n;
string ball;

int	checkR(int size)
{
	int cnt = 0;
	int ans = 0;
	int	rflag = 0;
	int bflag = 0;
	for (int i = 0; i < size; i++)
	{
		if (ball[i] == 'B')
			bflag = 1;
		else if (bflag == 1 && ball[i] == 'R')
			cnt++;
	}
	ans = cnt;
	cnt = 0;
	rflag = 0;
	bflag = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (ball[i] == 'B')
			bflag = 1;
		else if (bflag == 1 && ball[i] == 'R')
			cnt++;
	}
	if (ans < cnt)
		return ans;
	else
		return cnt;
}

int	checkB(int size)
{
	int cnt = 0;
	int ans = 0;
	int	rflag = 0;
	int bflag = 0;
	for (int i = 0; i < size; i++)
	{
		if (ball[i] == 'R')
			rflag = 1;
		else if (rflag == 1 && ball[i] == 'B')
			cnt++;
	}
	ans = cnt;
	cnt = 0;
	rflag = 0;
	bflag = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (ball[i] == 'R')
			rflag = 1;
		else if (rflag == 1 && ball[i] == 'B')
			cnt++;
	}
	if (ans < cnt)
		return ans;
	else
		return cnt;
}

void	solve(int size)
{
	int Rsum = checkR(size);
	int Bsum = checkB(size);
	if (Rsum < Bsum)
		cout<<Rsum;
	else
		cout<<Bsum;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	cin>>ball;
	int size = ball.size();
	for (int i = 0; i < size - 1; i++)
	{
		if ((ball[i] == 'R' && ball[i + 1] == 'B') || (ball[i] == 'B' && ball[i + 1] == 'R'))
		{
			solve(size);
			return 0;
		}
	}
	cout<<0;
	return 0;
}