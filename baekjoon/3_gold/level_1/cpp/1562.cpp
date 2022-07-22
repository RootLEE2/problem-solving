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
#define MAX_N 102
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000000
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N;

int dp[10][MAX_N][1 << 10];

const int ALL_NUM_BIT = (1 << 10) - 1;

int calc_num_of_stairs(int last, int len, int numBit) {
  if (len == N) return numBit == ALL_NUM_BIT ? 1 : 0;

  int &ret = dp[last][len][numBit];

  if (ret != -1) return ret;

  ret = 0;
  if (0 < last) {
    ret += calc_num_of_stairs(last - 1, len + 1, numBit | 1 << (last - 1));
    ret %= MOD;
  }
  if (last < 9) {
    ret += calc_num_of_stairs(last + 1, len + 1, numBit | 1 << (last + 1));
    ret %= MOD;
  }

  return ret;
}

void solve() {
  int sum = 0;

  for (int i = 1; i < 10; i++) {
    memset(dp, -1, sizeof(dp));

    sum += calc_num_of_stairs(i, 1, 1 << i);
    sum %= MOD;
  }

  cout << sum;
}

void input() {
  cin >> N;
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}