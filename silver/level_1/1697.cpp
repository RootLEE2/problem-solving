#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 100000

int map[MAX_SIZE];
queue<int> q;

void bfs(int dest) {
  int loc;
  while (!q.empty()) {
    loc = q.front(); q.pop();

    if (loc == dest) { break; }

    if (loc+1 <= MAX_SIZE && !map[loc+1]) {
      map[loc+1] = map[loc]+1;
      q.push(loc+1);
    }
    if (0 <= loc-1 && !map[loc-1]) {
      q.push(loc-1);
      map[loc-1] = map[loc]+1;
    }
    if (loc*2 <= MAX_SIZE && !map[loc*2]) {
      q.push(loc*2);
      map[loc*2] = map[loc]+1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, K;
  cin >> N >> K;
  q.push(N);

  bfs(K);
  cout << map[K];

  return 0;
}
