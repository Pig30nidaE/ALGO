#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main()
{
	int n;
	int p, d;
	int tmp;
	int tmp_index;
	int	result = 0;
	int	vec_second = 0;
	int day = 0;

	cin >> n;
	vector<pair<int, int> > vec;
	vector<pair<int, int> > vec2;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		vec.push_back(make_pair(d, p));
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		vec_second = vec[i].second;
		vec2.push_back(make_pair(vec[i].first, vec_second));
		day += 1;		
		result += vec_second;
		if (day > vec[i].first)
		{
			tmp = vec_second;
			tmp_index = -1;
			for (int j = 0; j < day; j++)
			{
				if (tmp > vec2[j].second)
				{
					tmp = vec2[j].second;
					tmp_index = j;
				}				
			}
			if (tmp_index != -1)
			{
				vec2.erase(vec2.begin() + tmp_index);
				result -= tmp;
				day -= 1;
			}
			else 
			{
				vec2.pop_back();
				result -= tmp;
				day -= 1;
			}
		}
	}
	printf("%d\n", result);
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