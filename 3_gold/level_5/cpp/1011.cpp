#include <iostream>
#include <math.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int T; cin >> T;
  int x, y, dist, distTmp, cnt;
  while (T--) {
    cin >> x >> y;
    dist = y - x;
    distTmp = sqrt(dist);
    cnt = pow(distTmp,2) == dist ? 2*distTmp - 1 : 2*distTmp;  // 2 * distTmp * (distTmp+1) / 2 - distTmp
    if (dist > distTmp * (distTmp+1)) { cnt ++; }  // dist - distTmp^2 > distTmp
    cout << cnt << '\n';
  }
}