#include <iostream>
#include <queue>
using namespace std;

bool visited[500][500] = {false};
int arr[500][500] = { 0 };
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
queue <pair <int , int> > q;

int bfsSize(int yy, int xx, int N, int M) {
    int size = 0;
    q.push(make_pair(yy, xx));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (!visited[y][x]) {
            visited[y][x] = true;
            size++;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[ny][nx] && arr[ny][nx] == 1) {
                size++;
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
    }
    return (size);
}

int main () {
    int N, M;

    cin >> N >> M;
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] && !visited[i][j]) {
                int size = bfsSize(i, j, M, N);
                cnt++;
                if (max < size) {
                    max = size;
                }
            }
        }
    }
    cout << cnt << "\n" << max;
}