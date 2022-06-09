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
#define MAX_N 200005
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

/**
 * @ref https://codeforces.com/blog/entry/76003
 * 
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>

int n;
ll t;
ll cumulativeSum[MAX_N];

void solve() {
  ll sumOfSegment = 0;

  ordered_set prevSum;
  prevSum.insert({0, 0});

  for (int right = 1; right <= n; right++) {
    int numOfLess = prevSum.order_of_key({cumulativeSum[right] - t + 1, -1});

    sumOfSegment += right - numOfLess;

    prevSum.insert({cumulativeSum[right], right});
  }

  cout << sumOfSegment << '\n';
}

void input() {
  cin >> n >> t;

  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;

    cumulativeSum[i] = a_i + cumulativeSum[i - 1];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
