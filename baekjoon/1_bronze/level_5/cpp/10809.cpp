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

string S;

int idx[NUM_OF_ALPHABET];

void solve() {
  memset(idx, -1, sizeof(idx));

  int len = S.length();

  for (int i = 0; i < len; i++) {
    int S_i = S[i] - 'a';

    int &val = idx[S_i];
    if (val == -1) val = i;
  }

  for (int i = 0; i < NUM_OF_ALPHABET; i++) {
    cout << idx[i] << ' ';
  }
}

void input() {
  cin >> S;
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}