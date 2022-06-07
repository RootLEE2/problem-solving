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
#define MAX_N 5003
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int n;
int a[MAX_N];
ll b[MAX_N];

void solve() {
  ll minSumOfMoves = INF;

  for (int i = 1; i <= n; i++) {
    memset(b, 0, sizeof(b));
    
    ll sumOfMoves = 0;
    
    for (int j = i - 1; j >= 1; j--) {
      ll moves = b[j + 1] / a[j] + 1;
      sumOfMoves += moves;
      
      b[j] = moves * a[j];
    }

    for (int j = i + 1; j <= n; j++) {
      ll moves = b[j - 1] / a[j] + 1;
      sumOfMoves += moves;
      
      b[j] = moves * a[j];
    }
    
    minSumOfMoves = min(minSumOfMoves, sumOfMoves);
  }

  cout << minSumOfMoves << '\n';
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
