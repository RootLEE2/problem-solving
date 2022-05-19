#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_NUM 10001

int T, N;
int L[MAX_NUM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> L[i];
    }
    sort(L, L+N);
    
    int level = 0;
    for (int i = 0; i < N-2; i++) {
      level = max(level, L[i+2] - L[i]);
    }
    level = max(level, L[N-1] - L[N-2]);  // 사실 없어도 됨. 근데 있을 때 더 빠름..
    cout << level << '\n';
  }

  return 0;
}