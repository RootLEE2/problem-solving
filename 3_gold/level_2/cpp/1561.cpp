#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define MAX_M 10000

short mTime[MAX_M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, M; cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> mTime[i];

  if (N <= M) { cout << N; return 0; }

  ll lft = 0, rgt = 60000000000, mid;
  ll last, cnt;
  while (lft <= rgt) {
    mid = (lft + rgt) / 2;

    cnt = M;
    for (int i = 0; i < M; i++)
      cnt += mid / mTime[i];

    if (cnt < N)
      lft = mid + 1;
    else {
      rgt = mid - 1;
      last = mid;
    }
  }

  cnt = M;
  for (int i = 0; i < M; i++)
    cnt += (last-1) / mTime[i];

  for (int i = 0; i < M; i++) {
    if (last % mTime[i] == 0) cnt++;
    if (cnt == N) {
      cout << i+1;
      break;
    }
  }
}