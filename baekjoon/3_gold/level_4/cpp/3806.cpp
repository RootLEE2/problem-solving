/**
 * @warning S의 '0'을 '1'로 변경하는 연산도 있으니 참고 바람.
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 100005
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

string S, T;

int solve() {
  int zeroToOne = 0;
  int oneToZero = 0;
  int someToZero = 0;
  int someToOne = 0;

  for (int i = 0; i < S.length(); i++) {
    if (S[i] == T[i]) continue;

    if (S[i] == '0' && T[i] == '1') {
      zeroToOne++;
    } else if (S[i] == '1' && T[i] == '0') {
      oneToZero++;
    } else if (S[i] == '?' && T[i] == '0') {
      someToZero++;
    } else if (S[i] == '?' && T[i] == '1') {
      someToOne++;
    }
  }

  if (zeroToOne + someToOne < oneToZero) {
    return -1;
  }

  int cnt = 0;

  int swap_zero_one = min(zeroToOne, oneToZero);

  cnt += swap_zero_one;
  zeroToOne -= swap_zero_one;
  oneToZero -= swap_zero_one;

  if (oneToZero != 0) {
    cnt += 2 * oneToZero;
    someToOne -= oneToZero;

    cnt += someToZero;
    cnt += someToOne;
  } else {
    cnt += zeroToOne;
    cnt += someToZero;
    cnt += someToOne;
  }

  return cnt;
}

void input() {
  cin >> S >> T;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int C;
  cin >> C;

  for (int i = 1; i <= C; i++) {
    input();
    cout << "Case " << i << ": " << solve() << '\n';
  }

  return 0;
}