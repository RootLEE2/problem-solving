#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 101

int M,N,K,cnt;
bool graph[MAX_SIZE][MAX_SIZE];
vector<int> result;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int y, int x) {
  graph[y][x] = true;
  cnt++;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (0 <= nx && 0 <= ny && nx < N && ny < M)
      if (!graph[ny][nx])
        dfs(ny,nx);
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int x1,y1,x2,y2;
  cin >> M >> N >> K;
  for (int i = 0; i < K; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for (int y = y1; y < y2; y++) for (int x = x1; x < x2; x++)  graph[y][x]=true;
  }

  for (int y = 0; y < M; y++)
    for (int x = 0; x < N; x++)
      if (!graph[y][x]) {
        cnt = 0;
        dfs(y,x);
        result.push_back(cnt);
      }

  sort(result.begin(), result.end());
  cout << result.size() << '\n';
  for (int i = 0; i < result.size(); i++)
    cout << result[i] << ' ';
}