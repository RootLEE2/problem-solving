#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_NK 300005
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

struct info {
  int weight;
  int value;

  bool operator<(const info& o) const {
    return weight < o.weight;
  }
};

int N, K;
info jewelry[MAX_NK];
int backpack[MAX_NK];

long long ans;

void find_max_value() {
  priority_queue<int> pq;
  int jewelryIdx = 0;

  for (int i = 0; i < K; i++) {
    while (jewelryIdx < N && jewelry[jewelryIdx].weight <= backpack[i]) {
      pq.push(jewelry[jewelryIdx].value);
      jewelryIdx++;
    }

    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }
}

void solve() {
  sort(jewelry, jewelry + N);
  sort(backpack, backpack + K);

  find_max_value();

  cout << ans;
}

void input() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> jewelry[i].weight >> jewelry[i].value;
  }

  for (int i = 0; i < K; i++) {
    cin >> backpack[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
