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

int M;

void solve() {
  int grundy = 0;

  for (int i = 0; i < M; i++) {
    int P_i; cin >> P_i;
    grundy ^= P_i;
  }

  cout << ((grundy != 0) ? "koosaga" : "cubelover");
}

void input() {
  cin >> M;
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}