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
#define MAX_N 502
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

int N;
int buildTime[MAX_N];
vector<int> nextBuilding[MAX_N];
int precBuildingCnt[MAX_N];

int dp[MAX_N];
int ans;

void solve() {
  for (int i = 1; i <= N; i++) {
    if (precBuildingCnt[i] != 0) continue;
    nextBuilding[0].push_back(i);
    precBuildingCnt[i] = 1;
  }
  
  queue<int> canBuild;
  canBuild.push(0);
  
  while (!canBuild.empty()) {
    int curBuild = canBuild.front();
    canBuild.pop();
    
    for (int nextBuild : nextBuilding[curBuild]) {
      dp[nextBuild] = max(dp[nextBuild], dp[curBuild] + buildTime[nextBuild]);
      
      precBuildingCnt[nextBuild] -= 1;
      if (precBuildingCnt[nextBuild] == 0) {
        canBuild.push(nextBuild);
      }
    }
  }
  
  for (int i = 1; i <= N; i++) {
    cout << dp[i] << '\n';
  }
}

void input() {
  cin >> N;
  
  for (int i = 1; i <= N; i++) {
    int tempTime; cin >> tempTime;
    buildTime[i] = tempTime;
    
    while (true) {
      int tempBuilding; cin >> tempBuilding;
      if (tempBuilding == -1) break;
      
      nextBuilding[tempBuilding].push_back(i);
      precBuildingCnt[i]++;
    }
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}