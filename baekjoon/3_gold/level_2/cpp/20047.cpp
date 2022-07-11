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
#define MAX_N 1003
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

int n, i, j;
string S, T;

string tempS;
char twoCoin[2];

bool finFlag;

int dfs(int idx, int cnt) {
  if (finFlag) return 0;

  if (idx == T.size()) {
    finFlag = true;
    return 1;
  }

  int ret = 0;

  if (cnt < 2 && twoCoin[cnt] == T[idx]) {
    ret |= dfs(idx + 1, cnt + 1);
  }
  if (tempS[idx - cnt] == T[idx]) {
    ret |= dfs(idx + 1, cnt);
  }

  return ret;
}

void solve() {
  if (!S.compare(T)) {
    cout << "YES";
    return;
  }
  if (count(S.begin(), S.end(), 'o') != count(T.begin(), T.end(), 'o')) {
    cout << "NO";
    return;
  }

  for (int s = 0; s < n; s++) {
    if (s == i || s == j) continue;
    tempS += S[s];
  }

  twoCoin[0] = S[i];
  twoCoin[1] = S[j];

  if (dfs(0, 0) == 1) cout << "YES";
  else cout << "NO";
}

void input() {
  cin >> n;
  cin >> S >> T;
  cin >> i >> j;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}