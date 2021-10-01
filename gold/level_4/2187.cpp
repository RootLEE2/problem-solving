// ver.1  2152KB
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<pair<int,int>,int>> point;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, A, B, r, c, S;
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    cin >> r >> c >> S;
    point.push_back(make_pair(make_pair(r, c), S));
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    r = point[i].first.first;
    c = point[i].first.second;
    S = point[i].second;

    for (int j = i+1; j < N; j++) {
      if (abs(r - point[j].first.first) < A && abs(c - point[j].first.second) < B) {
        ans = max(ans, abs(S - point[j].second));
      }
    }
  }
  cout << ans;
}


// ver.2  2032KB
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

struct val {
  int r, c, S;
} point[MAX_N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, A, B, r, c, S;
  cin >> N >> A >> B;
  for (int i = 0; i < N; i++) {
    cin >> r >> c >> S;
    point[i].r = r; point[i].c = c; point[i].S = S;
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    r = point[i].r;
    c = point[i].c;
    S = point[i].S;

    for (int j = i+1; j < N; j++)
      if (abs(r - point[j].r) < A && abs(c - point[j].c) < B)
        ans = max(ans, abs(S - point[j].S));
  }
  cout << ans;
}