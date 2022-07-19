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
#define MAX_N 502
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

int N;
int matrix[MAX_N][2];

int dp[MAX_N][MAX_N];

int divide_and_conq(int start, int end) {
  int &mat = dp[start][end];

  if (start == end) return 0;
  if (mat != 0) return mat;
  if (start + 1 == end) return mat = matrix[start][0] * matrix[start][1] * matrix[end][1];

  mat = INF;
  for (int i = start; i < end; i++) {
    int multiMat = matrix[start][0] * matrix[i][1] * matrix[end][1];
    mat = min(mat, divide_and_conq(start, i) + divide_and_conq(i + 1, end) + multiMat);
  }

  return mat;
}

void solve() {
  cout << divide_and_conq(1, N);
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int r, c; cin >> r >> c;
    matrix[i][0] = r;
    matrix[i][1] = c;
  }
}

int main() {
  fastio;
  
  input();
  solve();
  
  return 0;
}