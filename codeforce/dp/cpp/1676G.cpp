#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 4003
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

struct color {
  int white;
  int black;
};

int n;
int parent[MAX_N];
char s[MAX_N];

color numOfColor[MAX_N];

void solve() {
  for (int i = n; i > 0; i--) {
    int& numOfWhite = numOfColor[i].white;
    int& numOfBlack = numOfColor[i].black;
    
    if (s[i] == 'W') {
      numOfWhite++;
    }
    else if (s[i] == 'B') {
      numOfBlack++;
    }

    numOfColor[parent[i]].white += numOfWhite;
    numOfColor[parent[i]].black += numOfBlack;
  }

  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (numOfColor[i].white == numOfColor[i].black) {
      cnt++;
    }
  }

  cout << cnt << '\n';
}

void input() {
  cin >> n;

  parent[1] = 0;
  for (int i = 2; i <= n; i++) {
    cin >> parent[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    memset(numOfColor, 0, sizeof(numOfColor));
    
    input();
    solve();
  }

  return 0;
}
