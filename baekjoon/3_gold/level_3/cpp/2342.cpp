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
#define MAX_N 10004
#define MAX_LENGTH 100005
#define NUM_OF_DIR 5
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

vector<int> dirSeq;

int dp[MAX_LENGTH][NUM_OF_DIR][NUM_OF_DIR];

int energy[][5] = {
  { 1, 2, 2, 2, 2 },
  { 0, 1, 3, 4, 3 },
  { 0, 3, 1, 3, 4 },
  { 0, 4, 3, 1, 3 },
  { 0, 3, 4, 3, 1 }
};

int dfs(int leftFoot, int rightFoot, int cnt) {
  if (cnt == dirSeq.size()) return 0;

  int &ret = dp[cnt][leftFoot][rightFoot];

  if (ret != -1) return ret;

  const int moveDir = dirSeq[cnt];

  int leftMove = dfs(moveDir, rightFoot, cnt + 1) + energy[leftFoot][moveDir];
  int rightMove = dfs(leftFoot, moveDir, cnt + 1) + energy[rightFoot][moveDir];

  return ret = min(leftMove, rightMove);
}

void solve() {
  memset(dp, -1, sizeof(dp));
  
  cout << dfs(0, 0, 0);
}

void input() {
  int dir;
  for (cin >> dir; dir != 0; cin >> dir) {
    dirSeq.push_back(dir);
  }
}

int main() {
  fastio;

  input();
  solve();
  
  return 0;
}