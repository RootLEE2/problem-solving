/**
 * @ref https://velog.io/@ks1ksi/%EB%B0%B1%EC%A4%80-1014%EB%B2%88-%EC%BB%A8%EB%8B%9D
 * @ref https://www.secmem.org/blog/2019/10/19/handy-function-about-bit/
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

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 11
#define MAX_LENGTH 5003 >> 1
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int N;

void solve() {
  int ans = 1;

  for (int i = 2; i <= N; i++) {
    ans *= i;
  }

  cout << ans;
}

void input() {
  cin >> N;
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}