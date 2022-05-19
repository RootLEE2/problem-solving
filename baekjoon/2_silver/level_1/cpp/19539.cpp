#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, tmp, day, two;

  cin >> N; day = 0; two = 0;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    day += tmp;
    two += (int)(tmp/2);
  }

  if (day % 3 != 0) {
    cout << "NO"; return 0;
  }
  day = (int)(day/3);
  if (day <= two) { cout << "YES"; }
  else { cout << "NO"; }
  return 0;
}
