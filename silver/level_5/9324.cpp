#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 100
#define MAX_LENGTH 100001
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N;
string M[MAX_N];
int alphabetCnt[26];

bool is_OK(string __M) {
  memset(alphabetCnt, 0, sizeof(alphabetCnt));

  for (int i = 0; i < __M.length(); i++) {
    int alphabet = __M[i] - 'A';
    alphabetCnt[alphabet]++;

    if (alphabetCnt[alphabet] == 3) {
      if (__M[i] == __M[i+1]) {
        alphabetCnt[alphabet] = 0;
        i++;
      }
      else {
        return false;
      }
    }
  }

  return true;
}

void solve() {
  for (int i = 0; i < N; i++) {
    if (is_OK(M[i])) cout << "OK\n";
    else cout << "FAKE\n";
  }
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> M[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
