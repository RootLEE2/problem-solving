#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1003
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

struct edge {
  int to;
  int time;

  bool operator>(const edge& o) const {
    return time > o.time;
  }
};

int N, M, X;
vector<edge> adj[MAX_N];
vector<edge> revAdj[MAX_N];

int goDist[MAX_N];
int backDist[MAX_N];

void dijkstra(vector<edge> __adj[MAX_N], int *dist) {
  priority_queue<edge, vector<edge>, greater<edge>> pq;
  pq.push({ X, 0 });
  dist[X] = 0;

  while (!pq.empty()) {
    edge cur = pq.top();
    pq.pop();

    if (dist[cur.to] < cur.time) continue;

    for (edge e : __adj[cur.to]) {
      int nextTime = cur.time + e.time;

      if (nextTime < dist[e.to]) {
        dist[e.to] = nextTime;
        pq.push({ e.to, nextTime });
      }
    }
  }
}

void solve() {
  memset(goDist, 0x3f, sizeof(goDist));
  memset(backDist, 0x3f, sizeof(backDist));

  dijkstra(revAdj, goDist);
  dijkstra(adj, backDist);

  int ans = 0;

  for (int i = 1; i <= N; i++) ans = max(ans, goDist[i] + backDist[i]);
  cout << ans;
}

void input() {
  cin >> N >> M >> X;

  for (int i = 0; i < M; i++) {
    int from, to, time;
    cin >> from >> to >> time;

    adj[from].push_back({ to, time });
    revAdj[to].push_back({ from, time });
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
