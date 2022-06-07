#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 200005
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

int n, q;
map<int, int> a;

void solve() {
  for (int tq = 0; tq < q; tq++) {
    int b_j;
    cin >> b_j;

    int possibleA = 1 << 30;  // 2^30 = 1,073,741,824
    int ans_j = 0;

    while (possibleA != 0) {
      if (b_j < possibleA) {
        possibleA >>= 1;
        continue;
      }

      int cnt = min(a[possibleA], b_j / possibleA);
      ans_j += cnt;
      b_j -= possibleA * cnt;
      
      possibleA >>= 1;
    }

    if (b_j == 0) {
      cout << ans_j << '\n';
    } else {
      cout << "-1\n";
    }
  }
}

void input() {
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;

    a[a_i]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
