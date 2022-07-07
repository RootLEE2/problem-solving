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

int N;

priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void solve() {
  for (int i = 0; i < N; i++) {
    int val;
    cin >> val;

    if (max_heap.empty()) {
      max_heap.push(val);
    } else if (max_heap.size() == min_heap.size()) {
      max_heap.push(val);
    } else {
      min_heap.push(val);
    }

    if (!min_heap.empty() && min_heap.top() < max_heap.top()) {
      int maxVal = max_heap.top();
      int minVal = min_heap.top();

      max_heap.pop();
      min_heap.pop();

      max_heap.push(minVal);
      min_heap.push(maxVal);
    }

    cout << max_heap.top() << '\n';
  }
}

void input() {
  cin >> N;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}