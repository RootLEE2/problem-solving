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
#define MAX_N 302
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
  cout << "SHIP NAME      CLASS          DEPLOYMENT IN SERVICE\n";
  cout << "N2 Bomber      Heavy Fighter  Limited    21        \n";
  cout << "J-Type 327     Light Combat   Unlimited  1         \n";
  cout << "NX Cruiser     Medium Fighter Limited    18        \n";
  cout << "N1 Starfighter Medium Fighter Unlimited  25        \n";
  cout << "Royal Cruiser  Light Combat   Limited    4         \n";
}

void input() {
  
}

int main() {
  fastio;

  input();
  solve();

  return 0;
}