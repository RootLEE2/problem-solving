#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_M 300000
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N, k;

int ans;

void find_k_th() {
  int left = 1;
  int right = k;

  while (left <= right) {
    int mid = (left + right) / 2;

    int smallCnt = 0;
    for (int row = 1; row <= N; row++) {
      smallCnt += min(N, mid / row);
    }

    if (smallCnt < k) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
      ans = mid;
    }
  }
}

void solve() {
  find_k_th();

  cout << ans;
}

void input() {
  cin >> N >> k;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
