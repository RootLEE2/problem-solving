#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_M 300000
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int SLength;
int alphabetCnt[NUM_OF_ALPHABET];

int ans;

void dfs(int idx, int lastAlphabet) {
  if (idx == SLength) {
    ans++;
    return;
  }

  for (int i = 0; i < NUM_OF_ALPHABET; i++) {
    if (alphabetCnt[i] == 0) continue;
    if (lastAlphabet == i) continue;

    alphabetCnt[i]--;
    dfs(idx + 1, i);
    alphabetCnt[i]++;
  }
}

void solve() {
  dfs(0, -1);

  cout << ans;
}

void input() {
  string S;
  cin >> S;

  SLength = S.length();

  for (int i = 0; i < SLength; i++) {
    alphabetCnt[S[i] - 'a']++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
