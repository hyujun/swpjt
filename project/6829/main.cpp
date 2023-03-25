#include <iostream>
#include <queue>
using namespace std;
#define MAXN ((int)1e3)
int M, N;                      // 상자의 가로, 세로 칸 수
int map[MAXN + 10][MAXN + 10]; // 토마토 정보

struct QUE {
  int n, m, t;
};

void InputData() {
  cin >> M >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }
}

int bfs(void) {
  queue<QUE> que;
  int count = 0;
  int dn[] = {-1, 1, 0, 0};
  int dm[] = {0, 0, -1, 1};
  que = {};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 1) {
        que.push({i, j, 0});
      } else if (map[i][j] == 0) {
        count++;
      }
    }
  }

  if (count == 0)
    return 0;

  while (!que.empty()) {
    QUE cur = que.front();
    que.pop();
    for (int i = 0; i < 4; i++) {
      int nn = cur.n + dn[i];
      int mm = cur.m + dm[i];

      if ((nn < 0) || (nn >= N) || (mm < 0) || (mm >= M))
        continue;
      if (map[nn][mm] != 0)
        continue;
      if (--count == 0)
        return cur.t + 1;

      que.push({nn, mm, cur.t + 1});
      map[nn][mm] = 1;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int ans = -1;
  InputData(); // 입력

  // 여기서부터 작성
  ans = bfs();
  cout << ans << "\n"; // 출력
  return 0;
}