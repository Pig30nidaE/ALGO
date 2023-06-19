#include <stdio.h>

void insertion_sort(int *list, int n)
{
	int i, j, key;

	for (i = 1; i < n; i++)
	{	
		key = list[i]; 
		// 리스트의 두 번째 인자부터 정렬 시작
		// 배열에서 빼서 임시값 key에 저장
		for (j = i - 1; j >= 0 && list[j] > key; j--)
		{
			// 만약 key	보다 해당 인자가 크다면 
			list[j + 1] = list[j]; // 해당 인자의 인덱스를 뒤로 한칸 물림
		}
		list[j + 1] = key; 
		// 해당 인자보다 key가 크면 list[j]의 뒷자리에 key를 배치한다.
	}
}

int main(void)
{
	int	i;
	int list[6] = {5, 6, 2, 1, 3, 4};

	insertion_sort(list, 6); 

	for (int i = 0; i < 6; i++)
	{
		printf("%d", list[i]);
		printf(" ");
	}
}