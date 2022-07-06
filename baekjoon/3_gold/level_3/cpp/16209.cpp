#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 500005
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

int N;
vector<int> value[3];

void solve() {
  sort(value[0].begin(), value[0].end(), greater<int>());
  sort(value[2].begin(), value[2].end());

  vector<int> rearrangedA(N);
  int startIdx = 0;

  for (int i = 0; i < 3; i++) {
    int left = 0;
    int right = value[i].size() - 1;
    int valueIdx = 0;

    while (left <= right) {
      if (i == 0) {
        rearrangedA[startIdx + right] = value[i][valueIdx++];
        if (left == right) break;
        rearrangedA[startIdx + left] = value[i][valueIdx++];
      } else {
        rearrangedA[startIdx + left] = value[i][valueIdx++];
        if (left == right) break;
        rearrangedA[startIdx + right] = value[i][valueIdx++];
      }

      left++;
      right--;
    }

    startIdx += value[i].size();
  }

  for (int a_i : rearrangedA) {
    cout << a_i << ' ';
  }
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a_i;
    cin >> a_i;

    int idx;

    if (a_i < 0) {
      idx = 0;
    } else if (a_i == 0) {
      idx = 1;
    } else {
      idx = 2;
    }

    value[idx].push_back(a_i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}