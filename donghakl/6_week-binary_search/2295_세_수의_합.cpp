#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ft_binary_search(long long target, vector<long long >::iterator left, vector<long long >::iterator right, vector<long long >& nrr) {
    long long mid = distance(left, right) / 2;
    vector<long long >::iterator midIter = left + mid;
    
	if (left > right) //이거 필수
		return (-1);
    if (*midIter == target)
        return (distance(nrr.begin(), midIter));
    else if (*midIter < target)
        return (ft_binary_search(target, midIter + 1, right, nrr));
    else if (*midIter > target)
        return (ft_binary_search(target, left, midIter - 1, nrr));
    return (-1);
}

// void dfs(vector <int > nrr, int depth, int *min, int *result, vector <int >::iterator index)
// {
// 	if (depth == 4)
// 	{
// 		if (*result > *min)
// 		{
// 			if (ft_binary_search(*result, nrr.begin(), nrr.end() - 1, nrr) != -1)
// 			{
// 				*min = *result;
// 			}
// 		}
// 		return ;
// 	}

// 	for (;index < nrr.end() - 1; index++)
// 	{
// 		*result += *index;
// 		dfs(nrr, depth + 1, min, result, index);
// 		*result -= *index;
// 	}
// }

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, value;
	cin >> n;
	vector <long long > arr;
	vector <long long > sum;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		arr.push_back(value);
	}
	sort(arr.begin(), arr.end());
	// arr.erase(unique(arr.begin(), arr.end()), arr.end());
	for (vector <long long >::iterator i = arr.begin(); i < arr.end(); i++)
	{
		for (vector <long long >::iterator j = i; j < arr.end(); j++)
		{
			sum.push_back(*i + *j);
		}
	}
	sort(sum.begin(), sum.end());
	long long ind = sum.size();
		// for (long long i = sum[ind - 1]; i >= ind / 2; i--)
		// if (i < arr[ind - 1])
	int res;
	for (vector <long long >::iterator i = arr.end() - 1; i >= arr.begin(); i--)
	{
		for (vector <long long >::iterator j = i; j >= arr.begin(); j--)
		{
				res = *i - *j; 
			if (ft_binary_search(res, sum.begin(), sum.end(), arr) != -1)
			{
				printf("%lld\n", *i);
				return (0);
			}
		}
	}
}