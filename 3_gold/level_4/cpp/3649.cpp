// ver.1  1240ms
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int x, n;
int l[MAX_N];
int bsl, bsm, bsr, target;
bool flag = true;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> x) {
    cin >> n; x *= 10000000;
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l+n);

    flag = true;
    for (int i = 0; i < n-1 && flag; i++) {
      bsl = i+1; bsr = n-1;
      target = x - l[i];
      while (bsl <= bsr) {
        bsm = (bsl + bsr)/2;
        if (l[bsm] == target) {
          cout << "yes " << l[i] << ' ' << l[bsm] << '\n';
          flag = false;
          break;
        }
        if (target < l[bsm]) bsr = bsm-1;
        else bsl = bsm+1;
      }
    }
    if (flag) cout << "danger\n";
  }
}


// ver.2  1072ms
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int x, n;
int l[MAX_N];
int lft, rgt, sum;
bool flag;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while (cin >> x) {
    cin >> n; x *= 10000000;
    for (int i = 0; i < n; i++) cin >> l[i];
    sort(l, l+n);

    flag = false;
    lft = 0; rgt = n-1;
    while (lft < rgt) {
      sum = l[lft] + l[rgt];
      if (x == sum) {
        flag = true; break;
      }
      else if (x < sum) rgt--;
      else lft++;
    }

    if (flag) cout << "yes " << l[lft] << ' ' << l[rgt] << '\n';
    else cout << "danger\n";
  }
}