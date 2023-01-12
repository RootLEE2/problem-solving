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

void solve() {
  int N, M; cin >> N >> M;
  int A[102][102];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
    }
  }
  int B[102][102];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> B[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << A[i][j] + B[i][j] << ' ';
    }
    cout << '\n';
  }
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
