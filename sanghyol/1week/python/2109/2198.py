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
		pay_for_day.append((p, d))
	pay_for_day.sort(key=lambda x:(x[1], x[0]))
	largest_day = pay_for_day[-1][1]

	sum = 0
	for day in range(largest_day, 0, -1):
		num = 0
		max = 0
		if pay_for_day[-1][1] == day:
			sum += pay_for_day.pop()[0]
		else:
			try:
				index = -1
				max_index = 0
				while pay_for_day[index][1] >= day:
					num = pay_for_day[index][0]
					if (num > max):
						max = num
						max_index = index
					index -= 1
			except IndexError:
				pass
			if (max_index < 0):
				del pay_for_day[max_index]
			sum += max
	print(sum)

if __name__ == '__main__':
	main()