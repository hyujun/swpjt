#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
int N;                          // 가로, 세로 크기
char map[MAXN + 10][MAXN + 10]; // 지도정보

#define INF (1 << 30)
int visited[MAXN + 10][MAXN + 10];
struct QUE {
  int r, c;
};
queue<QUE> que;

int BFS() {
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      visited[i][j] = INF;
    }
  }
  que = {};
  que.push({1, 1});
  visited[1][1] = 0;
  while (!que.empty()) {
    QUE cur = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nr = cur.r + dr[i];
      int nc = cur.c + dc[i];
      if (map[nr][nc] == 0)
        continue;
      int ncost = visited[cur.r][cur.c] + map[nr][nc] - '0';
      if (visited[nr][nc] <= ncost)
        continue;
      que.push({nr, nc});
      visited[nr][nc] = ncost;
    }
  }
  return visited[N][N];
}

void InputData() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> &map[i][1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ans = -1;
  InputData(); // 입력

  ans = BFS(); // 여기서부터 작성

  cout << ans << "\n"; // 출력
  return 0;
}