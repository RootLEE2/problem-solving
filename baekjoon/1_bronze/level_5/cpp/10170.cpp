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

void solve() {
  cout << "NFC West       W   L  T\n";
  cout << "-----------------------\n";
  cout << "Seattle        13  3  0\n";
  cout << "San Francisco  12  4  0\n";
  cout << "Arizona        10  6  0\n";
  cout << "St. Louis      7   9  0\n";
  cout << "\n";
  cout << "NFC North      W   L  T\n";
  cout << "-----------------------\n";
  cout << "Green Bay      8   7  1\n";
  cout << "Chicago        8   8  0\n";
  cout << "Detroit        7   9  0\n";
  cout << "Minnesota      5  10  1\n";
}

void input() {
  
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}