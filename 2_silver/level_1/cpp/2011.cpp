#include <iostream>
#include <string>
using namespace std;
#define MAX_LEN 5001
#define MAX_RES 1000000

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string code;
  cin >> code;
  if (code[0] == '0')  { cout << 0; return 0; }

  int dp[MAX_LEN] = {1,1};
  int len = code.size();
  for (int i = 2; i <= len; i++) {
    if (code[i-1] != '0')
      dp[i] = dp[i-1] % MAX_RES;
    if (code[i-2] == '1' || (code[i-2] == '2' && code[i-1] < '7'))
      dp[i] = (dp[i] + dp[i-2]) % MAX_RES;
  }
  dp[0] = 0;

  cout << dp[len];
}