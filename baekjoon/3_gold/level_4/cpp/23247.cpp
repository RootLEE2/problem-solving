// ver.1  2468KB  420ms
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_SIZE 301

int m, n, ans;
int arr[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
queue<pair<int,int>> q;

int dx[] = {0,1};
int dy[] = {1,0};

void bfs(int y, int x) {
  int cx, cy, nx, ny, sum;
  q.push(make_pair(y,x));

  while (!q.empty()) {
    cy = q.front().first;
    cx = q.front().second;
    q.pop();

    for (int i = 0; i < 2; i++) {
      ny = cy + dy[i];
      nx = cx + dx[i];
      
      if (0 < nx && 0 < ny && nx <= n && ny <= m && !visited[ny][nx]) {
        sum = arr[ny][nx] - arr[ny][x-1] - arr[y-1][nx] + arr[y-1][x-1];
        visited[ny][nx] = true;
        if (sum == 10) ans++;
        else if (sum < 10) q.push(make_pair(ny,nx));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> m >> n;
  int tmp;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tmp;
      arr[i][j] = tmp + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
    }
  }
  
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] - arr[i][j-1] - arr[i-1][j] + arr[i-1][j-1] == 10) {
        ans++;
        continue;
      }

      for (int i = 1; i <= m; i++)
        memset(visited[i], false, n+1);
      bfs(i,j);
    }
  }
  cout << ans;
}


// ver.2  2376KB  24ms
#include <iostream>
using namespace std;
#define MAX_SIZE 301

int m, n, ans;
int arr[MAX_SIZE][MAX_SIZE];

int find(int y1, int x1, int y2, int x2) {
  return arr[y2][x2] - arr[y2][x1-1] - arr[y1-1][x2] + arr[y1-1][x1-1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> m >> n;
  int tmp;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tmp;
      arr[i][j] = tmp + arr[i][j-1] + arr[i-1][j] - arr[i-1][j-1];
    }
  }
  
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for(int c = j, r = m; c <= n; c++){
        if (10 < find(i, j, i, c)) break;
        while (10 < find(i, j, r, c)) r--;
        if (find(i, j, r, c) == 10) ans++;
      }
    }
  }
  cout << ans;
}