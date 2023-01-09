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

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_N 200005
#define MAX_WORD_LENGTH 10
#define MAX_M 200005

int N;
char word[MAX_N][MAX_WORD_LENGTH];
int M;
char S[MAX_M][MAX_WORD_LENGTH];

map<string, string> wordMapping;

void solve() {
  for (int i = 0; i < N; i++) {
    if (strlen(word[i]) <= 3) continue;

    char *temp = strdup(word[i]);
    sort(temp + 1, temp + strlen(temp) - 1);

    wordMapping[temp] = word[i];
  }

  for (int i = 0; i < M; i++) {
    if (strlen(S[i]) <= 3) {
      cout << S[i] << ' ';
      continue;
    }

    char *temp = strdup(S[i]);
    sort(temp + 1, temp + strlen(temp) - 1);

    cout << wordMapping[temp] << ' ';
  }
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> word[i];
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> S[i];
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}
