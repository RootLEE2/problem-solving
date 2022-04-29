#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 101
#define MAX_LENGTH 100001
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N, M, K;
float ability[MAX_N];

void solve() {
  sort(ability + 1, ability + N + 1);

  float sum = 0;

  for (int i = 0; i < K; i++) {
    sum += ability[N - i];
  }

  cout << fixed;
  cout.precision(1);
  cout << sum;
}

void input() {
  int num;
  float genreAbility;

  for (int i = 0; i < N; i++) {
    cin >> num >> genreAbility;

    ability[num] = max(ability[num], genreAbility);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> N >> M >> K;

  for (int i = 0; i < M; i++) {
    input();
  }

  solve();

  return 0;
}
