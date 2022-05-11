#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 20004
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

struct edge {
  int to;
  int weight;

  bool operator>(const edge& o) const {
    return weight > o.weight;
  }
};

int V, E, K;
vector<edge> adj[MAX_N];

int dist[MAX_N];

void dijkstra() {
  priority_queue<edge, vector<edge>, greater<edge>> pq;
  pq.push({ K, 0 });
  dist[K] = 0;

  while (!pq.empty()) {
    edge cur = pq.top();
    pq.pop();

    if (dist[cur.to] < cur.weight) continue;

    for (edge e : adj[cur.to]) {
      int nextWeight = cur.weight + e.weight;

      if (nextWeight < dist[e.to]) {
        dist[e.to] = nextWeight;
        pq.push({ e.to, nextWeight });
      }
    }
  }
}

void solve() {
  memset(dist, 0x3f, sizeof(dist));

  dijkstra();

  for (int i = 1; i <= V; i++) {
    if (dist[i] != INF) cout << dist[i] << '\n';
    else cout << "INF\n";
  }
}

void input() {
  cin >> V >> E >> K;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({ v, w });
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
