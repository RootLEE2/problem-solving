#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_N 100005
#define MAX_LENGTH 100005
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))
#define MOD(x) ((x) % 1000000007)
typedef long long ll;
// log2(100000) == 16.609xxx
// log2(200000) == 17.609xxx
// log2(500000) == 18.931xxx
// log2(1000000) == 19.931xxx

int n;
int a[MAX_N];
map<int, int> numOfA;
map<int, int> shouldDelete;

int deleteLast;

map<int, int> aInRange;

bool are_all_deletions_within_range() {
  for (const auto& element : shouldDelete) {
    if (aInRange[element.first] < element.second) {
      return false;
    }
  }
  return true;
}

bool explore_possible_case_in_range(int rangeSize) {
  if (are_all_deletions_within_range()) return true;

  for (int i = rangeSize; i <= deleteLast; i++) {
    aInRange[a[i - rangeSize]]--;
    aInRange[a[i]]++;

    if (are_all_deletions_within_range()) return true;
  }

  return false;
}

void solve() {
  int shouldDeleteNum = n - numOfA.size();

  if (shouldDeleteNum <= 1) {
    cout << shouldDeleteNum << '\n';
    return;
  }

  for (int rangeSize = shouldDeleteNum; rangeSize <= n; rangeSize++) {
    aInRange.clear();

    for (int i = 0; i < rangeSize; i++) {
      aInRange[a[i]]++;
    }

    if (explore_possible_case_in_range(rangeSize)) {
      cout << rangeSize << '\n';
      return;
    }
  }
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int a_i;
    cin >> a_i;

    a[i] = a_i;
    numOfA[a_i]++;

    if (1 < numOfA[a_i]) {
      deleteLast = i;
      shouldDelete[a_i]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
