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
#define MAX_N 1000000009
#define MAX_DIGIT 9 + 5
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

int dp[MAX_DIGIT][2];

void solve() {
  dp[0][0] = 1;
  dp[1][0] = 1;

  int nLength = 1;
  int tempN = n;
  
  while (tempN != 0) {
    int digitValue = tempN % 10;

    int carry = dp[nLength - 1][1];
    int notCarry = dp[nLength - 1][0];

    for (int i = 0; i < 2; i++) {
      int value = digitValue + i * 10;

      int getCarry;
      int notGet;

      if (value < 10) {
        notGet = value + 1;
      } else {
        notGet = 19 - value;
      }

      value--;
      if (value < 0) {
        getCarry = 0;
      } else if (value < 10) {
        getCarry = value + 1;
      } else {
        getCarry = 19 - value;
      }

      dp[nLength + 1][i] = carry * getCarry + notCarry * notGet;
    }

    tempN /= 10;
    nLength++;
  }

  cout << dp[nLength][0] * dp[nLength - 1][0] - 2 << '\n';
}

void input() {
  cin >> n;
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
