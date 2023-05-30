from collections import deque
import sys


def isAllTomatoRipe(tomatoFarm: list)->int:
    for i in tomatoFarm:
        for j in i:
            if not j:
                return 0
    return 1

def get_result(tomatoFarm: list, node_list: deque)->int:
    left, right, up, down = (-1, 0), (1, 0), (0, -1), (0, 1)
    pan = [left, right, up, down]
    days = 0
    while node_list:
        position = node_list.popleft()
        days_rem = position[2]
        for loc in pan:
            posi_loc_added = (position[0] + loc[0], position[1] + loc[1], position[2] + 1)
            if not tomatoFarm[posi_loc_added[0]][posi_loc_added[1]]:
                node_list.append(posi_loc_added)
                tomatoFarm[posi_loc_added[0]][posi_loc_added[1]] = 1
    if not isAllTomatoRipe(tomatoFarm):
        days_rem = -1
    return days_rem

def main()->None:
    input = sys.stdin.readline
    n, m = map(int, input().strip().split())
    tomatoFarm = list()
    rptmLctn = deque()
    tomatoFarm.append([2] * (n + 2))
    for i in range(1, m + 1):
        tomatoFarm.append(list(map(int, input().strip().split())))
        tomatoFarm[i].insert(0, 2)
        tomatoFarm[i].append(2)
    tomatoFarm.append([2] * (n + 2))
    for i in range(1, m + 1):
        for j in range(n + 1):
            if tomatoFarm[i][j] == 1:
                rptmLctn.append((i, j, 0))
    
    print(get_result(tomatoFarm, rptmLctn))            

if __name__ == '__main__':
    main()