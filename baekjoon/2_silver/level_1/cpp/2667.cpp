#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 31
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N;
char mapArr[MAX_N][MAX_N];

bool visited[MAX_N][MAX_N];
vector<int> apartSize;

int dr[] = { 0,0,-1,1 };
int dc[] = { -1,1,0,0 };

void bfs(int r, int c) {
  int cnt = 0;

  queue<pair<int, int>> q;
  q.push({ r, c });

  visited[r][c] = true;
  cnt++;

  while(!q.empty()) {
    int cr = q.front().first;
    int cc = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nr = cr + dr[i];
      int nc = cc + dc[i];

      if (nr < 0 || N <= nr || nc < 0 || N <= nc) continue;

      if (!visited[nr][nc] && mapArr[nr][nc] == '1') {
        visited[nr][nc] = true;
        q.push({ nr, nc });
        cnt++;
      }
    }
  }

  apartSize.push_back(cnt);
}

void solve() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j] && mapArr[i][j] == '1') {
        bfs(i, j);
      }
    }
  }

  sort(apartSize.begin(), apartSize.end());

  cout << apartSize.size() << '\n';
  for (int size : apartSize) {
    cout << size << '\n';
  }
}

void input() {
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> mapArr[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
