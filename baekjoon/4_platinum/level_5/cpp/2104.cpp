#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
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

int N;
int A[MAX_N];

ll max_queries(int left, int right) {
  if (right < left) return 0;
  if (left == right) return (ll)A[left] * A[left];

  int mid = (left + right) >> 1;  // int mid = (left + right) / 2;

  ll leftChild = max_queries(left, mid);
  ll rightChild = max_queries(mid + 1, right);

  ll maxValue = max(leftChild, rightChild);

  int l = mid;
  int r = mid + 1;

  ll sumA = A[l] + A[r];
  ll minA = min(A[l], A[r]);

  maxValue = max(maxValue, sumA * minA);

  while (left < l || r < right) {
    if (r < right && (A[l - 1] < A[r + 1] || l == left)) {
      r++;
      sumA += A[r];
      minA = min(minA, (ll)A[r]);
    }
    else {
      l--;
      sumA += A[l];
      minA = min(minA, (ll)A[l]);
    }

    maxValue = max(maxValue, sumA * minA);
  }

  return maxValue;
}

void solve() {
  cout << max_queries(1, N);
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
