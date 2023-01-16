#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define two2one(ball) ball.first * 10 + ball.second

typedef struct {
  pair<int,int> red;
  pair<int,int> blue;
  int cnt;
} tip_result;

int N, M;
char board[11][11];

pair<int,int> redStart;
pair<int,int> blueStart;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

bool visited[102][102];

void tip(pair<int,int> &loc, pair<int,int> delta) {
  while (board[loc.first + delta.first][loc.second + delta.second] != '#') {
    loc.first += delta.first;
    loc.second += delta.second;

    if (board[loc.first][loc.second] == 'O') return;
  }
}

int bfs() {
  queue<tip_result> q;
  q.push({ redStart, blueStart, 0});

  while (!q.empty()) {
    tip_result cur = q.front();
    q.pop();

    if (cur.cnt >= 10) break;

    visited[two2one(cur.red)][two2one(cur.blue)] = true;

    int nextCnt = cur.cnt + 1;
    for (int i = 0; i < 4; i++) {
      pair<int,int> nextRed = cur.red;
      pair<int,int> nextBlue = cur.blue;

      tip(nextRed, { dr[i], dc[i] });
      tip(nextBlue, { dr[i], dc[i] });

      if (board[nextBlue.first][nextBlue.second] == 'O') continue;
      if (board[nextRed.first][nextRed.second] == 'O') return nextCnt;

      if (nextRed.first == nextBlue.first && nextRed.second == nextBlue.second) {
        int redDist = abs(cur.red.first - nextRed.first) + abs(cur.red.second - nextRed.second);
        int blueDist = abs(cur.blue.first - nextBlue.first) + abs(cur.blue.second - nextBlue.second);

        if (redDist < blueDist) {
          nextBlue.first -= dr[i];
          nextBlue.second -= dc[i];
        } else {
          nextRed.first -= dr[i];
          nextRed.second -= dc[i];
        }
      }

      if (visited[two2one(nextRed)][two2one(nextBlue)]) continue;
      q.push({ nextRed, nextBlue, nextCnt });
    }
  }

  return -1;
}

void solve() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> board[i];
  }

  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < M - 1; j++) {
      if (board[i][j] == 'R') redStart = { i, j };
      else if (board[i][j] == 'B') blueStart = { i, j };
    }
  }

  cout << bfs();
}

int main() {
  fastio;

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
