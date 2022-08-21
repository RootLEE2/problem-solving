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
#define MAX_N 302
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

bool flag = true;
int A, B;

void solve() {
  if (A == 0 && B == 0) {
    flag = false;
    return;
  }

  if (B < A) cout << "Yes\n";
  else cout << "No\n";
}

void input() {
  cin >> A >> B;
}

int main() {
  fastio;

  while (flag) {
    input();
    solve();
  }

  return 0;
}