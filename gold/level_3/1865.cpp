#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 502
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

struct edge {
  int from, to;
  int time;
};

int N, M, W;
vector<edge> adj;

int dist[MAX_N];

bool check_negative_cycle() {
  for (edge e : adj) {
    int nextTime = dist[e.from] + e.time;

    if (nextTime < dist[e.to]) {
      return true;
    }
  }
  return false;
}

void bellman_ford() {
  dist[1] = 0;

  for (int i = 1; i < N; i++) {
    for (edge e : adj) {
      int nextTime = dist[e.from] + e.time;

      if (nextTime < dist[e.to]) {
        dist[e.to] = nextTime;
      }
    }
  }
}

void solve() {
  memset(dist, 0x3f, sizeof(dist));

  bellman_ford();

  if (check_negative_cycle()) cout << "YES\n";
  else cout << "NO\n";
}

void input() {
  cin >> N >> M >> W;

  for (int i = 0; i < M; i++) {
    int S, E, T;
    cin >> S >> E >> T;

    adj.push_back({ S, E, T });
    adj.push_back({ E, S, T });
  }

  for (int i = 0; i < W; i++) {
    int S, E, T;
    cin >> S >> E >> T;

    adj.push_back({ S, E, -T });
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int TC;

  for (cin >> TC; TC > 0; TC--) {
    adj.clear();

    input();
    solve();
  }

  return 0;
}
