#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int dp[10001] = {0, };
int main()
{
	int n;
	int p, d;
	int day = 1;

	cin >> n;
	vector<pair<int, int> > vec;
	vector<pair<int, int> > vec2;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		vec.push_back(make_pair(d, p));
	}


	int flag = 0;
	long sum = 0;
	long tmp = 0;
	int vec2_len =0;
	sort(vec.begin(), vec.end());
	for (int j = 0; j < n; j++)
	{
		if (j == 0)
			flag = vec[j].first;
		else if (flag != vec[j].first)
		{
			vec2.push_back(make_pair(flag , tmp));// remove
			vec.erase(vec.begin(), vec.end())
			vec2_len += 1;
			flag = vec[j].first;
			tmp = 0;
		}
		
		if (flag == vec[j].first)
		{
			if (tmp < vec[j].second)
				tmp = vec[j].second;
		}
	}
	vec2.push_back(make_pair(flag , tmp));// remove

	for (int i = 0; i < n; i++)
	{
		day = i;
		for (int j = 0; j < n; j++)
		{
		}
	}

	
	// tester
	printf("\n--tester--\n");
	for (int i = 0; i < n; i++)
	{
		printf("vec: %d, %d\n", vec[i].first, vec[i].second);
	}
	printf("\n");
	for (int i = 0; i <= vec2_len; i++)
	{
		printf("vec2: %d, %d\n", vec2[i].first, vec2[i].second);
	}

}

	// for (int i = 0; i < n; i++)
	// {
	// 	if (flag != vec[i].first)
	// 	{
	// 		flag = vec[i].first;
	// 		// printf("print flag:%d\n", flag);
	// 		sum += tmp;
	// 		tmp = 0;
	// 	}
		
	// 	if (flag == vec[i].first)
	// 	{
	// 		// printf("들어온 수:%d\n", vec[i].first);
	// 		if (tmp < vec[i].second)
	// 		{
	// 			tmp = vec[i].second;
	// 		}
	// 	}
	// }
	// sum += tmp;
	// printf("%ld", sum);