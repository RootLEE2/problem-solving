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
  int X;
  int N;

  cin >> X;
  cin >> N;

  int priceSum = 0;
  for (int i = 0; i < N; i++) {
    int a, b; cin >> a >> b;
    priceSum += a * b;
  }

  cout << (X == priceSum ? "Yes\n" : "No\n");
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
