#include <iostream>
using namespace std;

int temp[312500] = { 0 };

int main() {
  cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

  int N, A;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A;
    if (temp[A >> 5] & (1 << (A & 31))) {
      cout << A;
      return 0;
    }
    temp[A >> 5] |= 1 << (A & 31);
  }

  return 0;
}