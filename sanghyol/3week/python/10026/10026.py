import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

n = int(input())
drawing = list()
visited = set()
for _ in range(n):
	drawing.append(input().strip())

def	run_dfs(loc: tuple, flag: bool)->None:
	global n, drawing, visited
	pan = [(1, 0), (0, 1), (-1, 0), (0, -1)]
	check_color = drawing[loc[0]][loc[1]]
	for dir in pan:
		posi = (loc[0] + dir[0], loc[1] + dir[1])
		if posi[0] < 0 or posi[1] < 0:
			continue
		if posi[0] >= n or posi[1] >= n:
			continue
		if (posi in visited):
			continue
		if flag:
			if check_color == 'R' or check_color == 'G':
				if drawing[posi[0]][posi[1]] == 'R' or drawing[posi[0]][posi[1]] == 'G':
					visited.add(posi)
					run_dfs(posi, True)
			else:
				if (drawing[posi[0]][posi[1]] == check_color):
					visited.add(posi)
					run_dfs(posi, True)
		else:
			if drawing[posi[0]][posi[1]] == check_color:
				visited.add(posi)
				run_dfs(posi, False)

def main()->None:
	global n, drawing, visited
	count: int = 0
	for i in range(n):
		for j in range(n):
			if (i, j) not in visited:
				count += 1
				visited.add((i, j))
				run_dfs((i, j), False)
	print(count, end=" ")
	visited.clear()
	count = 0
	for i in range(n):
		for j in range(n):
			if (i, j) not in visited:
				count += 1
				visited.add((i, j))
				run_dfs((i, j), True)
	print(count)

if __name__ == '__main__':
	main()