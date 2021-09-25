// ver.1  12ms
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_M 10

bool MList[MAX_M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, M, tmp, j;
  bool flag;
  cin >> N >> M;
  for (int i = 0; i < M; i++)  { cin >> tmp; MList[tmp] = true; }

  int ans = abs(N - 100);
  for (int i = 0; i < 1000000; i++) {  // 999,999까지
    flag = true; tmp = 0; j = i;
    do {
      if (MList[j%10]) {  // 고장난 경우.
        flag = false;
        break;
      }
      tmp++;
      j /= 10;
    } while (j%1000000 != 0);

    if (flag) {  // 버튼이 고장 안 난 경우.
      ans = min(ans, abs(N-i) + tmp);
    }
  }
  cout << ans;
}


// ver.2  4ms
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAX_M 10

bool MList[MAX_M];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N, M, tmp, j;
  bool flag;
  cin >> N >> M;
  for (int i = 0; i < M; i++)  { cin >> tmp; MList[tmp] = true; }

  int ans = abs(N - 100);
  
  for (int i = N; i < 1000000; i++) {  // N보다 큰 경우.
    flag = true; tmp = 0; j = i;
    do {
      if (MList[j%10]) {  // 고장난 경우.
        flag = false;
        break;
      }
      tmp++;
      j /= 10;
    } while (j%1000000 != 0);

    if (flag) {  // 버튼이 고장 안 난 경우.
      ans = min(ans, abs(N-i) + tmp);
      break;
    }
  }
  
  for (int i = N; i > -1; i--) {  // N보다 작은 경우.
    flag = true; tmp = 0; j = i;
    do {
      if (MList[j%10]) {  // 고장난 경우.
        flag = false;
        break;
      }
      tmp++;
      j /= 10;
    } while (j%1000000 != 0);

    if (flag) {  // 버튼이 고장 안 난 경우.
      ans = min(ans, abs(N-i) + tmp);
      break;
    }
  }
  
  cout << ans;
}