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
            sum += map[i][j];
            if (map[i][j] > max) {
                max = map[i][j];
                index.first = i;
                index.second = j;
            }
        }
        if (index.first != -1 && index.second != -1) {
            if (!visited[index.first][index.second]) {
                to_sub += max;
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
                to_sub += max;
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