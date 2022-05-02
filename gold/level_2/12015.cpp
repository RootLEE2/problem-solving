#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1000000
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N;
int A[MAX_N];

vector<int> lastNum;

void find_lis() {
  for (int i = 0; i < N; i++) {
    int A_i = A[i];

    if (lastNum.empty() || lastNum.back() < A_i) lastNum.push_back(A_i);
    else {
      vector<int>::iterator low = lower_bound(lastNum.begin(), lastNum.end(), A_i);
      *low = A_i;
    }
  }
}

void solve() {
  find_lis();

  cout << lastNum.size();
}

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
