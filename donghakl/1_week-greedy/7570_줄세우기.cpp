#include <iostream>
#include <algorithm>

using namespace std;

int line[1000001];

int	check_sorted(int *array, int len)
{
	return (is_sorted(array, array + len));
}

int go_front(int target, int *array, int len)
{
	int tmp;

	for (int i = 0; i < len; i++)
	{
		if ((i != 0) && (target == array[i]))
		{
			tmp = array[i];
			for (int j = i; j > 0; j--)
				array[j] = array[j-1];
			array[0] = tmp;
			return (1);
		}
	}
	return (0);
}

int go_back(int target, int *array, int len)
{
	int tmp;

	for (int i = 0; i < len; i++)
	{
		if ((i != len) && (target == array[i]))
		{
			tmp = array[i];
			for (int j = i; j < (len - 1); j++)
				array[j] = array[j + 1];
			array[len-1] = tmp;
			return (1);
		}
	}
	return (0);
}

int check_hightvalue(int target, int i, int *array)
{
	for (; i > 0; i--)
	{
		if ((target + 1) == array[i])
			return (1);
	}
	return (0);
}

int	next_find(int index, int *array, int len, int *cnt)
{
	for (int i = 0; i < len; i++)
	{
		if (array[i] == index)
		{
			if (check_hightvalue(index, i, array))
			{
				go_back(index + 1, array, len);
				(*cnt) += 1;
			}
		}
	}
	return (index + 1);
}

int	sort(int *array, int len)
{
	int cnt = 0;

	while ()
	{

	}

	return (cnt);
}

int main()
{
	int len;
	int *array;
	int cnt;

	cin >> len;
	array = new int[len];	
	for (int i = 0; i < len; i++)
	{
		cin >> array[i];
	}
	if (len == 1)
	{
		printf("%d\n", 0);
		delete[] array;
		return (0);
	}
	cnt = sort(array, len);
	printf("%d\n", cnt);
	delete[] array;
}
