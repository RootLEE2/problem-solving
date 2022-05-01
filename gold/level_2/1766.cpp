#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 32001
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N, M;
vector<int> linkedProblem[MAX_N];
int precedentProblem[MAX_N];

vector<int> ans;

void topological_sorting() {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 1; i <= N; i++) {
    if (precedentProblem[i] == 0) {
      pq.push(i);
    }
  }

  while(!pq.empty()) {
    int problem = pq.top();
    pq.pop();

    ans.push_back(problem);

    for (int i = 0; i < linkedProblem[problem].size(); i++) {
      int nextProblem = linkedProblem[problem][i];

      precedentProblem[nextProblem]--;

      if (precedentProblem[nextProblem] == 0) {
        pq.push(nextProblem);
      }
    }
  }
}

void solve() {
  topological_sorting();

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << ' ';
  }
}

void input() {
  int A, B;

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    linkedProblem[A].push_back(B);
    precedentProblem[B]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
