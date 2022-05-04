// struct ver. 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1003
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

struct edge {
  int to;
  int cost;

  bool operator>(const edge& o) const {
    return cost > o.cost;
  }
};

int n, m;
int startCity, endCity;

vector<edge> adj[MAX_N];
int dist[MAX_N];
int preNode[MAX_N];

stack<int> ansRoute;

void calcul_route() {
  int routeFlag = endCity;

  while (routeFlag != 0) {
    ansRoute.push(routeFlag);
    routeFlag = preNode[routeFlag];
  }
}

void dijkstra() {
  priority_queue<edge, vector<edge>, greater<edge>> pq;
  pq.push({ startCity, 0 });
  dist[startCity] = 0;
  
  while (!pq.empty()) {
    edge cur = pq.top();
    pq.pop();

		if (dist[cur.to] < cur.cost) continue;  // 해당 코드 없으면 메모리 초과 혹은 시간 초과 발생. 

    for (edge e : adj[cur.to]) {
      int expectedCost = cur.cost + e.cost;

      if (expectedCost < dist[e.to]) {
        preNode[e.to] = cur.to;
        dist[e.to] = expectedCost;

        pq.push({ e.to, expectedCost });
      }
    }
  }
}

void solve() {
  memset(dist, 0x3f, sizeof(dist));

  dijkstra();

  calcul_route();

  cout << dist[endCity] << '\n';
  cout << ansRoute.size() << '\n';
  while (!ansRoute.empty()) {
    cout << ansRoute.top() << ' ';
    ansRoute.pop();
  }
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    adj[from].push_back({ to, cost });
  }
  cin >> startCity >> endCity;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}


/*
// pair<int, int> ver. 
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1003
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int n, m;
int startCity, endCity;

vector<pair<int, int>> adj[MAX_N];
int dist[MAX_N];
int preNode[MAX_N];

stack<int> ansRoute;

void calcul_route() {
  int routeFlag = endCity;

  while (routeFlag != 0) {
    ansRoute.push(routeFlag);
    routeFlag = preNode[routeFlag];
  }
}

void dijkstra() {
  priority_queue<pair<int, int>> pq;
  pq.push({ 0, startCity });
  dist[startCity] = 0;
  
  while (!pq.empty()) {
    int curCost = -pq.top().first;
    int curNode = pq.top().second;
    pq.pop();

		if (dist[curNode] < curCost) continue;

    for (pair<int, int> e : adj[curNode]) {
      int nextNode = e.second;
      int nextCost = curCost + e.first;

      if (nextCost < dist[nextNode]) {
        preNode[nextNode] = curNode;
        dist[nextNode] = nextCost;

        pq.push({ -nextCost, nextNode });
      }
    }
  }
}

void solve() {
  memset(dist, 0x3f, sizeof(dist));

  dijkstra();

  calcul_route();

  cout << dist[endCity] << '\n';
  cout << ansRoute.size() << '\n';
  while (!ansRoute.empty()) {
    cout << ansRoute.top() << ' ';
    ansRoute.pop();
  }
}

void input() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;

    adj[from].push_back({ cost, to });
  }
  cin >> startCity >> endCity;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
*/