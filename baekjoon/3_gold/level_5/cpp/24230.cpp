#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 200001
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N;
int C[MAX_N];
vector<int> tree[MAX_N];

int ans;
bool visited[MAX_N];

void dfs(int node, int parentColor) {
  visited[node] = true;

  if (C[node] != parentColor) {
    ans++;
  }

  for (int i = 0; i < tree[node].size(); i++) {
    if (visited[tree[node][i]]) continue;

    dfs(tree[node][i], C[node]);
  }
}

void solve() {
  dfs(1, 0);

  cout << ans;
}

void input() {
  int a, b;

  cin >> N;
  for (int i = 1; i < N + 1; i++) {
    cin >> C[i];
  }
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;

    tree[a].push_back(b);
    tree[b].push_back(a);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
