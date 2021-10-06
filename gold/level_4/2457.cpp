#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

struct Flower {
  int bloom, fall;
};

Flower list[MAX_N];

bool cmp(Flower a, Flower b) {
  if (a.bloom == b.bloom)
    return a.fall < b.fall;
  return a.bloom < b.bloom;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N; cin >> N;
  short bm, bd, fm, fd;
  for (int i = 0; i < N; i++) {
    cin >> bm >> bd >> fm >> fd;
    list[i].bloom = bm * 100 + bd;
    list[i].fall = fm * 100 + fd;
  }
  sort(list, list+N, cmp);

  int ans = 0, idx = -1, maxFall = 301;
  bool flag;
  for (int preFall = 301; preFall < 1200 && idx < N; preFall = maxFall) {
    flag = false; idx++;
    for (int i = idx; i < N; i++) {
      if (preFall < list[i].bloom)
        break;
      if (maxFall < list[i].fall) {
        maxFall = list[i].fall;
        idx = i;
        flag = true;
      }
    }

    if (flag) { ans++; }
    else { ans = 0; break; }
  }
  cout << ans;
}