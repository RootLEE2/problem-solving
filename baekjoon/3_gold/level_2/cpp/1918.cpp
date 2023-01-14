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

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

int operation_priority(char o) {
  if (o == '+' || o == '-') return 1;
  else if (o == '*' || o == '/') return 2;
  return -1;
}

void solve() {
  char infix[102]; cin >> infix;

  stack<char> s;

  for (int i = 0; i < strlen(infix); i++) {
    if ('A' <= infix[i] && infix[i] <= 'Z') {
      cout << infix[i];
      continue;
    }

    if (infix[i] == '(') {
      s.push('(');
      continue;
    }

    if (infix[i] == ')') {
      while (true) {
        if (s.top() == '(') {
          s.pop();
          break;
        }
        cout << s.top();
        s.pop();
      }
      continue;
    }


    if (s.empty() || s.top() == '(') {
      s.push(infix[i]);
      continue;
    }


    if (operation_priority(s.top()) < operation_priority(infix[i])) {
      s.push(infix[i]);
    } else {
      while (!s.empty() && operation_priority(infix[i]) <= operation_priority(s.top())) {
        cout << s.top();
        s.pop();
      }
      s.push(infix[i]);
    }
  }

  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }
}

int main() {
  fastio;

  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
