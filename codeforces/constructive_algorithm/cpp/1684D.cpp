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

int n, k;
int a[MAX_N];

ll totalDamage;

bool compare(int a, int b) {
  return a > b;
}

void solve() {
  if (n == k) {
    cout << "0\n";
    return;
  }

  sort(a + 1, a + n + 1, compare);

  for (int i = 1; i <= k; i++) {
    totalDamage -= a[i] - (n - i + 1);
  }

  cout << totalDamage << '\n';
}

void input() {
  cin >> n >> k;

  totalDamage = 0;

  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;

    a[i] = a_i + i;
    totalDamage += a_i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    input();
    solve();
  }

  return 0;
}
