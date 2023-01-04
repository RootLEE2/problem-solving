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

#define MAX_N 10004

int n;
string phoneNum[MAX_N];

void solve() {
  sort(phoneNum, phoneNum + n);

  bool flag = true;

  for (int i = 1; i < n; i++) {
    string prev = phoneNum[i - 1];
    string cur = phoneNum[i];

    if (prev.size() >= cur.size()) continue;
    if (prev == cur.substr(0, prev.size())) {
      cout << "NO\n";
      flag = false;
      break;
    }
  }

  if (flag) cout << "YES\n";
}

void input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> phoneNum[i];
  }
}

int main() {
  fastio;

  int t; cin >> t;
  while (t--) {
    input();
    solve();
  }

  return 0;
}
