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
#define MAX_LENGTH 102
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

string str1, str2, str3;
int len1, len2, len3;

int dp[MAX_LENGTH][MAX_LENGTH][MAX_LENGTH];

int find_LCS_length(int idx1, int idx2, int idx3) {
  if (idx1 == len1 || idx2 == len2 || idx3 == len3) return 0;

  int &ret = dp[idx1][idx2][idx3];

  if (ret != -1) return ret;

  int tempIncreaseOne;
  tempIncreaseOne = find_LCS_length(idx1 + 1, idx2, idx3);
  tempIncreaseOne = max(tempIncreaseOne, find_LCS_length(idx1, idx2 + 1, idx3));
  tempIncreaseOne = max(tempIncreaseOne, find_LCS_length(idx1, idx2, idx3 + 1));
  ret = max(ret, tempIncreaseOne);

  int tempIncreaseTwo;
  tempIncreaseTwo = find_LCS_length(idx1 + 1, idx2 + 1, idx3);
  tempIncreaseTwo = max(tempIncreaseTwo, find_LCS_length(idx1 + 1, idx2, idx3 + 1));
  tempIncreaseTwo = max(tempIncreaseTwo, find_LCS_length(idx1, idx2 + 1, idx3 + 1));
  ret = max(ret, tempIncreaseTwo);

  int tempIncreaseThree;
  tempIncreaseThree = find_LCS_length(idx1 + 1, idx2 + 1, idx3 + 1);
  if (str1[idx1] == str2[idx2] && str2[idx2] == str3[idx3]) tempIncreaseThree++;
  ret = max(ret, tempIncreaseThree);

  return ret;
}

void solve() {
  memset(dp, -1, sizeof(dp));

  len1 = str1.length();
  len2 = str2.length();
  len3 = str3.length();

  cout << find_LCS_length(0, 0, 0);
}

void input() {
  cin >> str1 >> str2 >> str3;
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}