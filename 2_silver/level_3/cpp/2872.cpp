// ver.1  28ms
#include <iostream>
using namespace std;
#define MAX_N 300001

int book[MAX_N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> book[i];
  }

  int cnt = N;
  for (int i = N-1; i >= 0; i--) {
    if (book[i] == cnt)
      cnt--;
  }
  cout << cnt;

  return 0;
}
