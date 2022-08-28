#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 100005
#define MAX_M 21
#define MAX_LENGTH 5003 >> 1
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD 1000000007
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

struct coor {
  int x, y;

  bool operator<(const coor &o) const {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};
struct CoorCmp {
  bool operator()(const coor& l, const coor& r) const { 
    if (l.y == r.y) return l.x < r.x;
    return l.y < r.y;
  }
};

int n;
vector<coor> point;

set<coor, CoorCmp> compPointSet;

int square_of_distance(coor a, coor b) {
  return SQUARE(a.x - b.x) + SQUARE(a.y - b.y);
}

void solve() {
  sort(point.begin(), point.end());

  compPointSet.insert(point[0]);
  compPointSet.insert(point[1]);

  int minDist = square_of_distance(point[0], point[1]);

  int setStartIdx = 0;
  for (int i = 2; i < n; i++) {
    if (minDist == 0) break;

    while (setStartIdx < i) {
      int xDist = point[i].x - point[setStartIdx].x;

      if (SQUARE(xDist) < minDist) break;

      compPointSet.erase(point[setStartIdx]);
      setStartIdx++;
    }

    if (setStartIdx != i) {
      int range = (int)sqrt(minDist) + 1;
      auto compStartIdx = compPointSet.upper_bound({ -INF, point[i].y - range });
      auto compEndIdx = compPointSet.lower_bound({ INF, point[i].y + range});

      for (auto it = compStartIdx; it != compEndIdx; it++) {
        minDist = min(minDist, square_of_distance(point[i], *it));
      }
    }
    
    compPointSet.insert(point[i]);
  }

  cout << minDist;
}

void input() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    point.push_back({ x, y });
  }
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}