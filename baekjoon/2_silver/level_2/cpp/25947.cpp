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

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_N 100005

int n, b, a;
int halfPrice[MAX_N];

void solve() {
  sort(halfPrice, halfPrice + n);
  
  int cnt;
  int sum = 0;

  for (cnt = 0; cnt < n; cnt++) {
    int tempSum = sum + halfPrice[cnt];
    if (a <= cnt) tempSum += halfPrice[cnt - a];

    if (b < tempSum) break;
    sum = tempSum;
  }

  cout << cnt--;
}

void input() {
  cin >> n >> b >> a;
  for (int i = 0; i < n; i++) {
    int temp; cin >> temp;
    halfPrice[i] = temp / 2;
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}
