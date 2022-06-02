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
#define MAX_N 2003
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

int n;
char matrix[MAX_N][MAX_N];

void solve() {
  int oneCnt = 0;
  int oneCntByDiag[MAX_N];

  memset(oneCntByDiag, 0, sizeof(oneCntByDiag));

  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      if (matrix[r][c] == '1') {
        int diagIdx = (n * (r - 1) + c - (r - 1)) % n;
        if (diagIdx == 0) diagIdx = n;

        oneCntByDiag[diagIdx]++;
        oneCnt++;
      }
    }
  }

  int maxOneCntByDiag = 0;

  for (int i = 1; i <= n; i++) {
    maxOneCntByDiag = max(maxOneCntByDiag, oneCntByDiag[i]);
  }

  int xorInDiag = n - maxOneCntByDiag;
  int xorInOther = oneCnt - maxOneCntByDiag;

  cout << xorInDiag + xorInOther << '\n';
}

void input() {
  cin >> n;

  for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
      cin >> matrix[r][c];
    }
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
