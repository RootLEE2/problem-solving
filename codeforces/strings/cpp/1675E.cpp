#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 200005
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

int n, k;
string s;

void solve() {
  int canUseOperation = k;
  char start[] = { s[0], -1 };
  char end[] = { -1, -1 };

  if (25 < canUseOperation) {
    for (int i = 0; i < n; i++) {
      s[i] = 'a';
    }
  } else {
    if (canUseOperation <= start[0] - 'a') {
      end[0] = start[0] - canUseOperation;
      canUseOperation = 0;
    } else {
      end[0] = 'a';
      canUseOperation -= start[0] - 'a';
    }
    s[0] = end[0];

    for (int i = 1; i < n; i++) {
      if (end[0] <= s[i] && s[i] <= start[0]) {
        s[i] = end[0];
      }
      else if (end[1] <= s[i] && s[i] <= start[1]) {
        s[i] = end[1];
      }
      else if (0 < canUseOperation) {
        if (s[i] - start[0] <= canUseOperation) {
          canUseOperation -= s[i] - start[0];
          start[0] = s[i];

          s[i] = end[0];
        } else {
          start[1] = s[i];
          end[1] = s[i] - canUseOperation;
          canUseOperation = 0;

          s[i] = end[1];
        }
      }
    }
  }

  cout << s << '\n';
}

void input() {
  cin >> n >> k;
  cin >> s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    input();
    solve();
  }

  return 0;
}

/*

[생각한 순서]

1. 입력 처리.
  - 알파벳 개수를 저장한다.
  - 큰 알파벳을 줄여서 여러 개의 작은 알파벳으로 만든다.
  - 맨 앞에 있는 알파벳을 최대한 작게 만든다. (a로 만들 수 있으면 a로 그게 아니면 최대한 작은 값으로)
  - 알파벳 별로 인덱스를 저장한다. (인접 리스트처럼)
  - 무작정 앞에서부터 알파벳을 줄이면 안된다.
  - 두번째를 약간 줄인 다음에 첫번째 알파벳을 줄였을 때 최소가 되는 경우가 있다.

2. 알파벳을 줄이는 횟수를 저장해둔다.
  - 첫번째 알파벳을 줄이고 두번째로 넘어갈 때 해당 알파벳 줄이는 횟수를 사용한다.

3. 가능한 경우.
  - 첫번째 알파벳을 k번 줄였을 때 'a'가 안되는 경우 : 단순히 첫번째 알파벳만 줄인다.
  - 첫번째 알파벳을 k번 줄였을 때 'a'가 되는 경우 : 다음번째 알파벳을 반복적으로 확인한다.

4. k가 26 이상인 경우는 모두 'a'이다.
  - 가장 큰 알파벳부터 줄이면 모두 'a'로 만들 수 있다.

5. 최종 아이디어.
  - 변경이 시작되는 지점(이하 start)을 저장한다. 처음에는 첫번째 알파벳이 저장될 것이다.
  - 첫번째 알파벳을 가능한 최소로 만들고, 그 값을 저장한다. 변경이 끝나는 지점(이하 end)이 될 것이다.
  - 이 과정에서 사용한 operation의 사용 횟수(이하 useOperation)를 저장한다.
  - 두번째 알파벳으로 넘어가서 start와 end 범위 이내이면 줄이고, 그게 아니라면 남은 operation 횟수(k - useOperation)만큼 줄여준다.
  - 이 과정에서 줄인 범위를 기존 start와 end에 적용하거나, 범위 밖이면 다음 인덱스에 저장한다.
    - start와 end는 각각 2차원 배열로 만들면 된다.
    - 기존 start와 end의 범위 밖에서 operation을 진행하는 경우는 한 번 밖에 없다.
    - 그 이유는 operation 결과가 범위 밖이라는 것 자체가 모든 operation을 진행 도중에 다 사용한 경우이기 때문이다.
  - 이 작업을 총 n번 진행한다.

6. 구현.

*/
