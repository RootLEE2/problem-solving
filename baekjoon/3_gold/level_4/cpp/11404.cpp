#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 102
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int n, m;
int cost[MAX_N][MAX_N];

void floyd() {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

void solve() {
  floyd();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ((cost[i][j] != INF) ? cost[i][j] : 0) << ' ';
    }
    cout << '\n';
  }
}

void input() {
  cin >> n >> m;

  memset(cost, 0x3f, sizeof(cost));
  for (int i = 1; i <= n; i++) {
    cost[i][i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    cost[a][b] = min(cost[a][b], c);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
