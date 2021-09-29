// ver.1  4092KB  24ms
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_SIZE 1001

int N, M, ans;
string gallery[MAX_SIZE];
bool paint[MAX_SIZE][MAX_SIZE];

char pattern[4][2][2] = {
  {
    {'X','X'},
    {'.','.'}
  },
  {
    {'.','X'},
    {'.','X'}
  },
  {
    {'.','.'},
    {'X','X'}
  },
  {
    {'X','.'},
    {'X','.'}
  }
};

bool match(int p, int y, int x) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      if (gallery[y+i][x+j] != pattern[p][i][j])
        return false;
  return true;
}
void hang(int y, int x) {
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      paint[y+i][x+j] = true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> M >> N;
  for (int i = 0; i < M; i++) cin >> gallery[i];

  for (int p = 0; p < 4; p++) {
    for (int i = 0; i < M; i++) memset(paint[i], false, N);

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (!paint[i][j] && match(p,i,j)) {
          hang(i,j); ans++;
        }
      }
    }
  }
  cout << ans;
}


// ver.2  3000KB  20ms
#include <iostream>
using namespace std;
#define MAX_SIZE 1001

int N, M, ans;
char gallery[MAX_SIZE][MAX_SIZE];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> M >> N;
  for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cin >> gallery[i][j];

  for (int i = 0; i < M; i++) {
    int up = 0, down = 0;
    for (int j = 0; j < N; j++) {
      if (gallery[i][j] == 'X' && gallery[i+1][j] == '.') {
        ans += down / 2;
        down = 0; up++;
      }
      else if (gallery[i][j] == '.' && gallery[i+1][j] == 'X') {
        ans += up / 2;
        up = 0; down++;
      }
      else {
        ans += up / 2; up = 0;
        ans += down / 2; down = 0;
      }
    }
  }
  for (int j = 0; j < N; j++) {
    int left = 0, right = 0;
    for (int i = 0; i < M; i++) {
      if (gallery[i][j] == 'X' && gallery[i][j+1] == '.') {
        ans += right / 2;
        right = 0; left++;
      }
      else if (gallery[i][j] == '.' && gallery[i][j+1] == 'X') {
        ans += left / 2;
        left = 0; right++;
      }
      else {
        ans += left / 2; left = 0;
        ans += right / 2; right = 0;
      }
    }
  }
  cout << ans;
}