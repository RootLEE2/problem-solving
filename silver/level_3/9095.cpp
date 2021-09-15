#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int numOfCase[11];
  numOfCase[1] = 1;
  numOfCase[2] = 2;
  numOfCase[3] = 4;
  for (int i = 4; i < 11; i++) {
    numOfCase[i] = numOfCase[i-1] + numOfCase[i-2] + numOfCase[i-3];
  }

  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    cout << numOfCase[n] << '\n';
  }

  return 0;
}
