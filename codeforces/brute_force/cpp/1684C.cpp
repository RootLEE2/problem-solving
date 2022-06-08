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
#define MAX_NM 200005
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

int n, m;

void solve() {
  vector<vector<int>> a(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> shouldSwapIdx;

  for (int i = 1; i <= n; i++) {
    vector<int> sortA_i = a[i];
    
    for (int j = 1; j <= m; j++) {
      sortA_i[j] = a[i][j];
    }
    
    sort(sortA_i.begin(), sortA_i.end());
    
    for (int j = 1; j <= m; j++) {
      if (sortA_i[j] != a[i][j]) {
        shouldSwapIdx.push_back(j);
      }
    }

    if (!shouldSwapIdx.empty()) break;
  }

  if (shouldSwapIdx.empty()) {
    cout << "1 1\n";
    return;
  } else if (2 < shouldSwapIdx.size()) {
    cout << "-1\n";
    return;
  }
  
  for (int i = 1; i <= n; i++) {
    swap(a[i][shouldSwapIdx[0]], a[i][shouldSwapIdx[1]]);
    
    for (int j = 2; j <= m; j++) {
      if (a[i][j] < a[i][j - 1]) {
        cout << "-1\n";
        return;
      }
    }
  }

  cout << shouldSwapIdx[0] << ' ' << shouldSwapIdx[1] << '\n';
}

void input() {
  cin >> n >> m;
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
