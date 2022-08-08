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
#define MAX_N 16
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int x, y;

void solve() {
  if (0 < x) {
    if (0 < y) {
      cout << 1;
    } else {
      cout << 4;
    }
  } else {
    if (0 < y) {
      cout << 2;
    } else {
      cout << 3;
    }
  }
}

void input() {
  cin >> x >> y;
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}