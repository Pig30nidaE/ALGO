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

// 1932

int tri[502][502];
int	dpTri[502][502];
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for (int i = 0; i < n; i++)
	{ 
		for (int j = 0; j < i + 1; j++)
			cin>>tri[i][j];
	}
	
	dpTri[0][0] = tri[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			if (j == 0)
				dpTri[i][j] = dpTri[i - 1][j] + tri[i][j];
			else if (j == i)
				dpTri[i][j] = dpTri[i - 1][j - 1] + tri[i][j];
			else
				dpTri[i][j] = max(dpTri[i - 1][j - 1], dpTri[i - 1][j]) + tri[i][j]; 
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dpTri[n - 1][i]);
	}
	cout<<ans;
	return 0;
}