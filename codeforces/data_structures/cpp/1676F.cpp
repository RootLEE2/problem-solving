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
map<int, int> aMap;
vector<int> valsInA;

int left, right;
int maxBetweenIR;
int lAtMax;

void calcul_max(int left, int right) {
  if (maxBetweenIR < right - left) {
    maxBetweenIR = right - left;
    lAtMax = left;
  }
}

void find_max_between_l_and_r() {
  int left = -1;
  int right = -2;
  maxBetweenIR = -1;

  for (int aVal : valsInA) {
    if (aMap[aVal] < k) {
      calcul_max(left, right);

      left = -1;
      right = -2;

      continue;
    }

    if (right + 1 != aVal) {
      calcul_max(left, right);

      left = aVal;
      right = aVal;
    } else {
      right++;
    }
  }

  calcul_max(left, right);
}

void solve() {
  sort(valsInA.begin(), valsInA.end());

  find_max_between_l_and_r();

  if (maxBetweenIR == -1) {
    cout << "-1\n";
  } else {
    cout << lAtMax << ' ' << lAtMax + maxBetweenIR << '\n';
  }
}

void input() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int aVal;
    cin >> aVal;

    if (aMap.count(aVal) == 0) {
      valsInA.push_back(aVal);
      aMap[aVal] = 1;
    } else {
      aMap[aVal]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    input();
    solve();

    aMap.clear();
    valsInA.clear();
  }

  return 0;
}

/*

[생각한 순서]

1. 입력 처리 방법.
  - 배열 a에 있는 정수들이 몇 번 나왔는지를 저장해야 한다.
  - 입력받은 a_i 값을 인덱스로 하는 배열 칸에 +1을 해준다. 
  - 그런데 a_i의 값 범위가 int 범위이다... 위 방법이 불가능하다.
  - 값을 배열에 넣을 때 map 구조를 사용하면 될 것 같다.
  - map 변수의 key로 사용되는 값들을 vector에 저장해두고, 나중에 오름차순 정렬하여 l과 r를 구할 때 사용하면 될 것 같다.

2. a 값들에 대한 비교 판단.
  - 개수가 k 이상인지 아닌지 확인한다.
  - k개 이상이 아니라면 연속되는 l과 r 취소한다. l 값을 -1로 하면 될 것 같다.
  - 그리고 r - l의 최댓값 갱신을 시도해본다.
  - k개라면 값이 연속되는지 확인한다.
  - 연속되지 않는다면 r - l의 최댓값 갱신을 시도해보고 l과 r을 현재 값으로 변경한다.
  - 연속된다면 r을 +1 해준다.

3. 특이한 케이스 고려.
  - a의 값 중 k개 이상인 경우가 하나도 없어 -1을 출력해야 하는 경우에 대비해 r - 1 최댓값의 초기 값을 -1로 설정해둔다.

*/
