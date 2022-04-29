#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_M 300000
#define MAX_LENGTH 100001
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N, M;
int numOfJewelry[MAX_M];
int maxNum;

bool up_or_down(int __mid) {
  int studentNum = 0;

  for (int i = 0; i < M; i++) {
    studentNum += numOfJewelry[i] / __mid;

    if (numOfJewelry[i] % __mid != 0) {
      studentNum++;
    }
  }

  return N < studentNum;
}

void solve() {
  int left = 1;
  int right = maxNum;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (up_or_down(mid)) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }

  cout << left;
}

void input() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> numOfJewelry[i];

    maxNum = max(maxNum, numOfJewelry[i]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
