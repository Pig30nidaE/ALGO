
#include <iostream>
#include <queue>
using namespace std;

int arr[50][50];
bool visited[50][50];
queue<pair<int, int > > q;
int M, N, K;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};

void bfs(int xx, int yy) {
    q.push(make_pair(xx, yy));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && !visited[nx][ny] && arr[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void init() {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            arr[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

int main () {
    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        init();
        cin >> M >> N >> K;
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> y >> x;
            arr[x][y] = 1;
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[j][k] == 1 && !visited[j][k]) {
                    bfs(j, k);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}