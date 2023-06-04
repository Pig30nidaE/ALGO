#include <iostream>
#include <queue>

using namespace std;

int N, M;
char arr[100][100];
int cnt[100][100] = {0,};
bool visited[100][100] = { false, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<pair <int, int> > q;

void bfs(int x, int y) {
    visited[x][y] = 1;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && 0 <= ny && nx < N && ny < M && arr[nx][ny] == '1' && !visited[nx][ny] ) {
                cnt[nx][ny] = cnt[x][y] + 1;
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main () {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    bfs(0, 0);
    cout << cnt[N - 1][M - 1] + 1;
}