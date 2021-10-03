#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1001

typedef struct asg {
  int d, w;
} Asg;
Asg NList[MAX_N];
bool todo[MAX_N];

bool cmp(Asg a, Asg b) {
  if (a.w == b.w)
    return a.d < b.d;
  return a.w > b.w;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N; cin >> N;
  for (int i = 0; i < N; i++) cin >> NList[i].d >> NList[i].w;
  sort(NList, NList+N, cmp);

  int d, ans = 0;
  for (int i = 0; i < N; i++) {
    d = NList[i].d;
    while (d != 0) {
      if (!todo[d]) {
        ans += NList[i].w;
        todo[d] = true;
        break;
      }
      d--;
    }
  }
  cout << ans;
}