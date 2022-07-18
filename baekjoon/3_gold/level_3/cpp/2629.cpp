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
#define MAX_N 31
#define MAX_WEIGHT 15003
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

int numOfWeight;
vector<int> weight;
int numOfMarble;

bool dp[MAX_N][MAX_WEIGHT];

void find_possible_weight(int idx, int cumulWeight) {
  if (dp[idx][cumulWeight]) return;
  
  dp[idx][cumulWeight] = true;

  if (idx == numOfWeight) return;

  find_possible_weight(idx + 1, cumulWeight);
  find_possible_weight(idx + 1, cumulWeight + weight[idx]);
  find_possible_weight(idx + 1, abs(cumulWeight - weight[idx]));
}

void solve() {
  find_possible_weight(0, 0);

  for (int i = 0; i < numOfMarble; i++) {
    int marble_i; cin >> marble_i;
    
    if (15000 < marble_i) cout << "N ";
    else if (dp[numOfWeight][marble_i]) cout << "Y ";
    else cout << "N ";
  }
}

void input() {
  cin >> numOfWeight;
  for (int i = 0; i < numOfWeight; i++) {
    int weight_i; cin >> weight_i;
    weight.push_back(weight_i);
  }

  cin >> numOfMarble;
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}