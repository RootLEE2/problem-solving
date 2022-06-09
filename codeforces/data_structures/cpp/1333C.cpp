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
#define MAX_N 200005
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
ll cumulativeSum[MAX_N];

void solve() {
  ll numOfGoodSubarrays = 0;
  
  map<ll, int> cumulativeSumIdx;
  cumulativeSumIdx[0] = 1;
  
  int leftBound = 0;

  for (int i = 1; i <= n; i++) {
    ll curSum = cumulativeSum[i];
    
    leftBound = max(leftBound, cumulativeSumIdx[curSum]);

    numOfGoodSubarrays += i - leftBound;

    cumulativeSumIdx[curSum] = i + 1;
  }

  cout << numOfGoodSubarrays << '\n';
}

void input() {
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;
    
    cumulativeSum[i] = a_i + cumulativeSum[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
