import sys

def get_result(target_comb: list, target_list: list, num_set: set):
    for i in target_list:
        for j in target_comb:
            if i + j in num_set:
                return i + j
    return 0

def main()->None:
    input = sys.stdin.readline
    n: int = int(input())
    num_list = list()
    for _ in range(n):
        num_list.append(int(input()))
    num_list.sort(reverse=True)
    max_num = num_list[0]
    left_list = num_list[:n//2]
    right_list = num_list[n//2:]
    num_list = set(num_list)
    left_comb = list()
    right_comb = list()
    for i in left_list:
        for j in left_list:
            res = i + j
            if res < max_num:
                left_comb.append(res)
    for i in right_list:
        for j in right_list:
            res = i + j
            if res < max_num:
                right_comb.append(res)
    answer_list = list()
    answer_list.append(get_result(right_comb, right_list, num_list))
    answer_list.append(get_result(right_comb, left_list, num_list))
    answer_list.append(get_result(left_comb, right_list, num_list))
    answer_list.append(get_result(left_comb, left_list, num_list))
    print(answer_list)
    print(max(answer_list))

if __name__ == '__main__':
    main()