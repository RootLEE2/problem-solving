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
#define MAX_N 10004
#define MAX_LENGTH 5003 >> 1
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int x;
int A, B;

void solve() {
  cout << "Case #" << x << ": " << A << " + " << B << " = " << A + B << '\n';
}

void input() {
  cin >> A >> B;
}

int main() {
  fastio;

  int T; cin >> T;
  for (x = 1; x <= T; x++) {
    input();
    solve();
  }
  
  return 0;
}