#include <iostream>
#include <algorithm>

using namespace std;

int ft_binary_search(int target, vector<int>::iterator left, vector<int>::iterator right, vector<int>& nrr) {
    int mid = distance(left, right) / 2;
    vector<int>::iterator midIter = left + mid;
    
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

void dfs(vector <int > nrr, int depth, int *min, int *result, vector <int >::iterator index)
{
	if (depth == 4)
	{
		if (*result > *min)
		{
			if (ft_binary_search(*result, nrr.begin(), nrr.end() - 1, nrr) != -1)
			{
				*min = *result;
			}
		}
		return ;
	}

	for (;index < nrr.end() - 1; index++)
	{
		*result += *index;
		dfs(nrr, depth + 1, min, result, index);
		*result -= *index;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, value;
	cin >> n;
	vector <int > arr;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		arr.push_back(value);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	int min = 0;
	int result = 0;
	int len = distance(arr.begin(), arr.end());
	if (len <= 4)
		printf("%d\n", arr[3]);
	else
	{
		dfs(arr, 1, &min, &result, arr.begin());
		printf("%d\n", min);
	}
}