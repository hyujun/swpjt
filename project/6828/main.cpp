#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)

int N, M;       // 장기판 행의 수, 열의 수
int R, C, S, K; // 말 행과 열, 졸 행과 열

int visited[MAXN + 10][MAXN + 10];

struct chess {
  int h, w, t;
};

void InputData() {
  cin >> N >> M;
  cin >> R >> C >> S >> K;
}

int y_dir[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int x_dir[] = {-1, 1, 2, 2, 1, -1, -2, -2};

int bfs(int &start, int &end) {
  queue<chess> q;

  fill(&visited[0][0], &visited[MAXN + 10 - 1][MAXN + 10 - 1], 0);
  q.push({R, C, 0});
  visited[R][C] = 1;

  while (!q.empty()) {
    struct chess cur = q.front();
    q.pop();
    if ((cur.h == S) && (cur.w == K))
      return cur.t;

    for (int i = 0; i < 8; i++) {
      int hh = cur.h + y_dir[i];
      int ww = cur.w + x_dir[i];

      if ((hh < 1) || (hh > N) || (ww < 1) || (ww > M))
        continue;
      if (visited[hh][ww] == 1)
        continue;

      q.push({hh, ww, cur.t + 1});
      visited[hh][ww] = 1;
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
  ans = bfs(R, C);

  cout << ans << "\n"; // 출력
  return 0;
}