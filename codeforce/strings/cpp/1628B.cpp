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
vector<string> s;

bool two_word_check() {
  map<char, set<string>> sLenTwo;
  map<char, set<string>> sLenThree;

  for (string s_i : s) {
    string sTemp = s_i;
    int siLength = sTemp.length();

    reverse(s_i.begin(), s_i.end());

    if (siLength == 2) {
      for (string s_two : sLenTwo[s_i[0]]) {
        if (s_i.compare(s_two) == 0) return true;
      }

      for (string s_three : sLenThree[s_i[0]]) {
        if (s_three.compare(0, 2, s_i) == 0) return true;
      }

      sLenTwo[sTemp[0]].insert(sTemp);
    }
    else if (siLength == 3) {
      for (string s_two : sLenTwo[s_i[0]]) {
        if (s_i.compare(0, 2, s_two) == 0) return true;
      }

      for (string s_three : sLenThree[s_i[0]]) {
        if (s_three.compare(s_i) == 0) return true;
      }

      sLenThree[sTemp[0]].insert(sTemp);
    }
  }

  return false;
}

void solve() {
  for (string s_i : s) {
    if (s_i[0] == s_i[s_i.length() - 1]) {
      cout << "YES\n";
      return;
    }
  }
  
  if (two_word_check()) cout << "YES\n";
  else cout << "NO\n";
}

void input() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    s.push_back(temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    s.clear();
    
    input();
    solve();
  }

  return 0;
}