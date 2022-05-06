#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_F 100005 * 2
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int F;
string friend1, friend2;
map<string, int> nameIdx;

int flagIdx;
int parent[MAX_F];
int networkSize[MAX_F];

void union_network(int node1, int node2) {
  if (networkSize[node1] < networkSize[node2]) {
    swap(node1, node2);
  }

  parent[node2] = node1;
  networkSize[node1] += networkSize[node2];
  networkSize[node2] = 0;
}

int find_parent(int node) {
  if (node == parent[node]) return node;

  return parent[node] = find_parent(parent[node]);
}

void add_friend_to_map() {
  if (nameIdx.count(friend1) == 0) {
    nameIdx[friend1] = flagIdx++;
  }
  if (nameIdx.count(friend2) == 0) {
    nameIdx[friend2] = flagIdx++;
  }
}

void solve() {
  add_friend_to_map();

  int friend1Parent = find_parent(nameIdx[friend1]);
  int friend2Parent = find_parent(nameIdx[friend2]);

  if (friend1Parent == friend2Parent) {
    cout << networkSize[friend1Parent] << '\n';
  } else {
    union_network(friend1Parent, friend2Parent);
    cout << max(networkSize[friend1Parent], networkSize[friend2Parent]) << '\n';
  }
}

void input() {
  cin >> F;

  for (int i = 0; i < F; i++) {
    cin >> friend1 >> friend2;

    solve();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int caseNum;
  
  for (cin >> caseNum; caseNum > 0; caseNum--) {
    nameIdx.clear();
    flagIdx = 0;

    for (int i = 0; i < MAX_F; i++) {
      parent[i] = i;
      networkSize[i] = 1;
    }

    input();
  }

  return 0;
}
