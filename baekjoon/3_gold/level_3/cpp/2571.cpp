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

#define MAX_N 102

int N;
pair<int,int> xSortCoor[MAX_N], ySortCoor[MAX_N];
int canvas[MAX_N][MAX_N];

const int maxLenSideRect = 10;

void solve() {
  for (int r = 0; r < MAX_N; r++) {
    for (int c = 0; c < MAX_N; c++) {
      if (canvas[r][c] == 0) continue;
      canvas[r][c] += canvas[r - 1][c];
    }
  }

  int maxArea = 100;

  for (int r = 0; r < MAX_N; r++) {
    for (int c = 0; c < MAX_N; c++) {
      int height = canvas[r][c];

      for (int width = 1; width < MAX_N - c; width++) {
        height = min(height, canvas[r][c + width - 1]);
        if (height == 0) break;
        maxArea = max(maxArea, height * width);
      }
    }
  }

  cout << maxArea;
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x_i, y_i; cin >> x_i >> y_i;

    for (int r = x_i; r < x_i + maxLenSideRect; r++) {
      for (int c = y_i; c < y_i + maxLenSideRect; c++) {
        canvas[r][c] = 1;
      }
    }
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}