#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX_N 101

int N, num[MAX_N];
bool visited[MAX_N];
vector<int> ans;

void dfs(int cur, int start) {
  if (visited[cur]) {
    if (cur == start)
      ans.push_back(cur);
    return;
  }
  
  visited[cur] = true;
  dfs(num[cur], start);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> num[i];

  for (int i = 1; i <= N; i++) {
    memset(visited, false, N+1);
    dfs(i,i);
  }
  
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << '\n';
}