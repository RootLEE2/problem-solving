// ver.1  36ms
#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;
#define MAX_NUM 50001

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, minVal;
  cin >> n;
  
  vector<int> dp(n+1);
  dp[0] = 0; dp[1] = 1;

  for (int i = 2; i < n+1; i++) {
    minVal = MAX_NUM;
    for (int j = 1; j <= int(sqrt(i)); j++) {
      minVal = min(minVal, dp[i-j*j]);
    }
    dp[i] = minVal + 1;
  }
  cout << dp[n];
}