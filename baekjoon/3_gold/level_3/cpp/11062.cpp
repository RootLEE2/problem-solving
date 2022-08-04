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
#define MAX_N 1003
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N;
int card[MAX_N];

int dp[MAX_N][MAX_N];

int card_game(int turn, int leftIdx, int rightIdx) {
  if (rightIdx < leftIdx) return 0;

  int &ret = dp[leftIdx][rightIdx];

  if (ret != -1) return ret;

  int leftChoice = card_game(turn + 1, leftIdx + 1, rightIdx);
  int rightChoice = card_game(turn + 1, leftIdx, rightIdx - 1);

  if (turn & 1) {
    return ret = max(card[leftIdx] + leftChoice, card[rightIdx] + rightChoice);
  } else {
    return ret = min(leftChoice, rightChoice);
  }
}

void solve() {
  memset(dp, -1, sizeof(dp));

  cout << card_game(1, 1, N) << '\n';
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> card[i];
  }
}

int main() {
  fastio;

  int T; cin >> T;
  while (T--) {
    input();
    solve();
  }
  
  return 0;
}