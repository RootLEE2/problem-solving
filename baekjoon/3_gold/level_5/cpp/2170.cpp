#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

struct Point {
  int x, y;
};

Point list[MAX_N];

bool cmp(Point a, Point b) {
  if (a.x == b.x)
    return a.y < b.y;
  return a.x < b.x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> list[i].x >> list[i].y;
  sort(list, list+N, cmp);

  int ans = 0;
  int start = list[0].x, last = list[0].y;
  for (int i = 1; i < N; i++) {
    if (last < list[i].x) {
      ans += last - start;
      start = list[i].x;
      last = list[i].y;
    }
    else {
      last = max(last, list[i].y);
    }
  }
  ans += last - start;
  cout << ans;
}