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
  char T[1000006];
  char P[1000006];
  fgets(T, sizeof(T), stdin);
  fgets(P, sizeof(P), stdin);

  const int len_T = strlen(T) - 1;
  const int len_P = strlen(P) - 1;
  const int last_idx_P = len_P - 1;

  int failFunc[1000006];
  for (int pos = 1, cnt = 0; pos < len_P; pos++) {
    while (cnt > 0 && P[pos] != P[cnt]) cnt = failFunc[cnt - 1];
    if (P[pos] == P[cnt]) failFunc[pos] = ++cnt;
  }

  vector<int> ansPos;
  for (int pos = 0, cnt = 0; pos < len_T; pos++) {
    while (cnt > 0 && T[pos] != P[cnt]) cnt = failFunc[cnt - 1];
    if (T[pos] == P[cnt]) {
      if (cnt == last_idx_P) {
        ansPos.push_back(pos - last_idx_P);
        cnt = failFunc[cnt];
      } else {
        cnt++;
      }
    }
  }

  cout << ansPos.size() << '\n';
  for (int p : ansPos) {
    cout << p + 1 << ' ';
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
