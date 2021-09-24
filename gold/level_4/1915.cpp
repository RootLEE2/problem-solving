#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1001

short dp[MAX_SIZE][MAX_SIZE];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string S;  cin >> S;
    for (int j = 0; j < m; j++)  dp[i][j+1] = S[j]-'0';
  }

  short ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (dp[i][j]) {
        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
        ans = max(ans, dp[i][j]);
      }
  cout << ans*ans;
}