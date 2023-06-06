import sys
sys.setrecursionlimit(1000000)


def run_dfs(count: int, drawing: list, loc: tuple, visited: set, rg_weakness_flag: bool, check_color: str, n: int)->int:
	pan = [(0, 1), (1, 0), (0, -1), (-1, 0)]
	for dir in pan:
		posi = (loc[0] + dir[0], loc[1] + dir[1])
		if (posi[0] >= 0 and posi[1] >= 0 and posi[0] < n and posi[1] < n):
			if rg_weakness_flag:
				if check_color == 'R' or check_color == 'G':
					if posi not in visited and ('R' or 'G') == drawing[posi[0]][posi[1]]:
						visited.add(posi)
						return_color = run_dfs(count + 1, drawing, posi, visited, rg_weakness_flag, check_color, n)
				else:
					if posi not in visited and check_color == drawing[posi[0]][posi[1]]:
						visited.add(posi)
						return_color = run_dfs(count + 1, drawing, posi, visited, rg_weakness_flag, check_color, n)
			else:
				if posi not in visited and check_color == drawing[posi[0]][posi[1]]:
					visited.add(posi)
					return_color = run_dfs(count + 1, drawing, posi, visited, rg_weakness_flag, check_color, n)
				else:
					pass
		else:
			pass
	return count



def get_rg_weakness_result(drawing: list, n : int)->str:
	visited = set()
	count = dict()
	count['R'] = 0
	count['G'] = 0
	count['B'] = 0
	for i in range(n):
		for j in range(n):
			if j not in visited:
				visited.add((i, j))
				count[run_dfs(count, drawing, (i, j), visited, True, drawing[i][j], n)] += 1
	return count

def get_normal_result(drawing: list, n: int)->int:
	visited = set()
	count = dict()
	count['R'] = 0
	count['G'] = 0
	count['B'] = 0
	for i in range(n):
		for j in range(n):
			if j not in visited:
				visited.add((i, j))
				count += run_dfs(count, drawing, (i, j), visited, False, drawing[i][j], n)
	return count

def main()->None:
	input = sys.stdin.readline
	n = int(input())
	drawing = list()
	for _ in range(n):
		drawing.append(list(input().strip()))
	print(f"{get_normal_result(drawing, n)} {get_rg_weakness_result(drawing, n)}")

if __name__ == '__main__':
	main()