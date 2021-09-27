#include <iostream>
using namespace std;
#define MAX_N 10
#define MAX_LEN 50

int N, M, P[MAX_N];
int minWith0[2], minVal[2] = {0,51};
int ans[MAX_LEN], len;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  cin >> P[0]; minWith0[1] = P[0];
  for (int i = 1; i < N; i++) {
    cin >> P[i];
    if (P[i] <= minWith0[1]) {
      minWith0[0] = i; minWith0[1] = P[i];
    }
    if (P[i] <= minVal[1]) {
      minVal[0] = i; minVal[1] = P[i];
    }
  }
  cin >> M;

  if (M < minVal[1]) {
    cout << 0;
  }
  else {
    M -= minVal[1];
    len = (int)(M / minWith0[1]) + 1;
    M %= minWith0[1];
    
    ans[0] = minVal[0];
    for (int i = 1; i < len; i++) ans[i] = minWith0[0];

    for (int i = 0; i < len; i++) {
      for (int j = N-1; ans[i] < j; j--) {
        if (P[j] - P[ans[i]] <= M) {
          M -= P[j] - P[ans[i]];
          ans[i] = j;
          break;
        }
      }
      cout << ans[i];
    }
  }
}