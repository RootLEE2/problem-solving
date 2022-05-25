/**
 * @ref https://www.acmicpc.net/blog/view/21
 * @ref https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/09/algorithm-fenwick-tree/
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1033
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

int N, M;
int A[MAX_N][MAX_N];

int fenwickTree[MAX_N][MAX_N];

int sum_queries(int r, int c) {
  int sum = 0;

  for (int i = r; i > 0; i -= i & -i) {
    for (int j = c; j > 0; j -= j & -j) {
      sum += fenwickTree[i][j];
    }
  }

  return sum;
}

int calcul_sum(int r1, int c1, int r2, int c2) {
  return sum_queries(r2, c2) - sum_queries(r1 - 1, c2) - sum_queries(r2, c1 - 1) + sum_queries(r1 - 1, c1 - 1);
}

void update_query(int r, int c, int delta) {
  for (int i = r; i <= N; i += i & -i) {
    for (int j = c; j <= N; j += j & -j) {
      fenwickTree[i][j] += delta;
    }
  }
}

void solve() {
  for (int i = 0; i < M; i++) {
    int w;
    cin >> w;

    if (w == 0) {
      int x, y, c;
      cin >> x >> y >> c;

      int delta = c - A[x][y];
      update_query(x, y, delta);
      A[x][y] = c;
    }
    else if (w == 1) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;

      cout << calcul_sum(x1, y1, x2, y2) << '\n';
    }
  }
}

void input() {
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> A[i][j];

      update_query(i, j, A[i][j]);
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
