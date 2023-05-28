#include <iostream>
#include <vector>
using namespace std;

long long    cal_all_arr_sum(int **map, int** visited, int n, int m) {
    long long sum = 0;
    long long max;
    long long to_sub = 0;
    pair <int, int> index;

    for (int i = 0;i < n;i++) {
        max = 0;
        index.first = -1;
        index.second = -1;
        for (int j = 0;j < m;j++) {
            sum += map[i][j]; // 먼저 모든 박스의 합을 구함.
            if (map[i][j] > max) {
                max = map[i][j];
                index.first = i;
                index.second = j;
            }
        }
        if (index.first != -1 && index.second != -1) {
            if (!visited[index.first][index.second]) {
                to_sub += max; // 모든 피자박스의 합에서 Side의 각각 최대크기를 빼줌.
                visited[index.first][index.second] = 1;
            }
        }
    }
    for (int i = 0;i < m;i++) {
        max = 0;
        index.first = -1;
        index.second = -1;
        for (int j = 0;j < n;j++) {
            if (map[j][i] > max) {
                max = map[j][i];
                index.first = j;
                index.second = i;
            }
        }
        if (index.first != -1 && index.second != -1) {
            if (!visited[index.first][index.second]) {
                to_sub += max; // 여기서는 Front를 빼주는데 단, visited를 체크하며 이미 방문했던 곳은 빼지 않음.
                visited[index.first][index.second] = 1;
            }
        }
    }
    return sum - to_sub;
}

int main() {
    int n, m;

    cin >> n >> m;
    int **map;
    int **visited;

    map = new int *[n];
    visited = new int *[n];
    for (int i = 0;i < n;i++) {
        map[i] = new int[m];
        visited[i] = new int[m];
        for (int j = 0;j < m;j++) {
            cin >> map[i][j];
            visited[i][j] = 0;
        }
    }

    cout << cal_all_arr_sum(map, visited, n, m);

    for (int i = 0;i < n;i++) {
        delete[] map[i];
    }
    for (int i = 0;i < n;i++) {
        delete[] visited[i];
    }
    delete map;
    delete visited;
}