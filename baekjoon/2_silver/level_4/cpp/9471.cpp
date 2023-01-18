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

void solve()
{
  int N, M;
  cin >> N >> M;

  int a1 = 1, a2 = 1;
  int cnt = 0;
  
  do {
    int temp = a1;
    a1 = a2;
    a2 = (temp + a2) % M;

    cnt++;
  } while (!(a1 == 1 && a2 == 1));

  cout << N << ' ' << cnt << '\n';
}

int main()
{
  fastio;

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
