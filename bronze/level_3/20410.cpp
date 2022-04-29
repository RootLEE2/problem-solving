#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 500000
#define MAX_LENGTH 101
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int m, seed, x1, x2;

bool isCorrect(int a, int c) {
  if (x1 == (a * seed + c) % m
    && x2 == (a * x1 + c) % m) {
    return true;
  }
  return false;
}

void solve() {
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < m; j++) {
      if (isCorrect(i, j)) {
        cout << i << ' ' << j;
        return;
      }
    }
  }
}

void input() {
  cin >> m >> seed >> x1 >> x2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
