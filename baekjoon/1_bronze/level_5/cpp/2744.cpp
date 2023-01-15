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
  char str[102]; cin >> str;

  for (int i = 0; i < strlen(str); i++) {
    if ('a' <= str[i] && str[i] <= 'z') {
      cout << (char)('A' + str[i] - 'a');
    } else {
      cout << (char)('a' + str[i] - 'A');
    }
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
