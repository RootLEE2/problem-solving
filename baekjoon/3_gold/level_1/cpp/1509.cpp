#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
// #include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1003
#define MAX_LENGTH 2503
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

string s;
int sLength;

int isPal[MAX_LENGTH][MAX_LENGTH];
int dp[MAX_LENGTH];

int check_palindrome(int start, int end) {
  int &ret = isPal[start][end];

  if (ret != -1) return ret;
  if (end <= start) return ret = 1;

  if (s[start] != s[end]) return ret = 0;

  return ret = check_palindrome(start + 1, end - 1);
}

void solve() {
  memset(isPal, -1, sizeof(isPal));

  sLength = s.length();
  s = ' ' + s;

  for (int i = 1; i <= sLength; i++) {
    dp[i] = dp[i - 1] + 1;

    for (int j = 1; j < i; j++) {
      if (check_palindrome(j, i) != 1) continue;
      dp[i] = min(dp[i], dp[j - 1] + 1);
    }
  }

  cout << dp[sLength];
}

void input() {
  cin >> s;
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}