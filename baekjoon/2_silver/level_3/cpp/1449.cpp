// ver.1  0ms
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NUM 1001

int N, L, cnt, temp;
int loc[MAX_NUM];
bool checked[MAX_NUM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    cin >> loc[i];
  }
  sort(loc, loc+N);

  for (int i = 0; i < N; i++) {
    if (!checked[i]) {
      cnt++;
      temp = loc[i] + L - 1;
      for (int j = i+1; loc[j] <= min(temp, MAX_NUM); j++) {
        checked[j] = true;
      }
    }
  }
  cout << cnt;

  return 0;
}
