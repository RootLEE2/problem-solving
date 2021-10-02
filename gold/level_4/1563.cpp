#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD(x) ((x) % 1000000)

int atdc[MAX_N][2][3];  // attendance

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N; cin >> N;
  atdc[0][0][0] = atdc[0][1][0] = atdc[0][0][1] = 1;

  for (int i = 1; i < N; i++) {
    atdc[i][0][0] = MOD(atdc[i-1][0][0] + atdc[i-1][0][1] + atdc[i-1][0][2]);
    atdc[i][0][1] = atdc[i-1][0][0];
    atdc[i][0][2] = atdc[i-1][0][1];
    atdc[i][1][0] = MOD(atdc[i-1][0][0] + atdc[i-1][0][1] + atdc[i-1][0][2] + atdc[i-1][1][0] + atdc[i-1][1][1] + atdc[i-1][1][2]);
    atdc[i][1][1] = atdc[i-1][1][0];
    atdc[i][1][2] = atdc[i-1][1][1];
  }

  int ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++)
      ans += atdc[N-1][i][j];
  ans = MOD(ans);
  cout << ans;
}