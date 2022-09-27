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
#define MAX_N 200005
#define MAX_M 100005
#define MAX_LENGTH 2503
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
int a[1003];

void solve() {
  int minStock, maxStock;
  int totalMaxStock = 0;
  minStock = maxStock = a[1];

  for (int i = 2; i <= N; i++) {
    if (a[i] < minStock) {
      totalMaxStock = max(totalMaxStock, maxStock - minStock);
      minStock = maxStock = a[i];
    } else if (maxStock < a[i]) {
      maxStock = a[i];
    }
  }
  totalMaxStock = max(totalMaxStock, maxStock - minStock);

  cout << totalMaxStock;
}

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}