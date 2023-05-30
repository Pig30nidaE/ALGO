import sys


def main()->None:
	input = sys.stdin.readline
	n: int = int(input())
	if (not n):
		return print(0)
	pay_for_day: list = list()
	largest_day = 0
	for _ in range(n):
		p, d = map(int, input().strip().split())
		pay_for_day.append((p, d)) # 각각의 정보를 list에 담음.
	pay_for_day.sort(key=lambda x:(x[1], x[0])) # 정보의 리스트를 1순위: day, 2순위: pay로 정렬함.
	largest_day = pay_for_day[-1][1]

	sum = 0
	for day in range(largest_day, 0, -1): # day의 뒤에서부터 반복문 돌림
		num = 0
		max = 0
		if pay_for_day[-1][1] == day:
			sum += pay_for_day.pop()[0] # 만약 날짜와 같으면 그냥 해당 날짜 pop 해주면 됨.
		else: # 같지 않은 경우는, 제한기간이 해당 날짜보다 더 긴 경우, 예를 들어 : 한 대학의 d == 10 인데 반복문의 날짜는 9
			try:
				index = -1
				max_index = 0
				while pay_for_day[index][1] >= day: # 그럴 경우 d의 제한 기간을 맞추는 한에서 pay를 비교함.
					num = pay_for_day[index][0]
					if (num > max):
						max = num
						max_index = index
					index -= 1
			except IndexError: # 이건 모두 pop했을 때의 예외처리
				pass
			if (max_index < 0):
				del pay_for_day[max_index] # pop할수없으니 해당 인덱스 제거
			sum += max
	print(sum)

if __name__ == '__main__':
	main()