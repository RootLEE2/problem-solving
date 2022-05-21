#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 2 * 100005
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

struct minCost {
  ll of1;
  ll ofN;
};

int n;
ll aGrade[MAX_N];
ll bGrade[MAX_N];

minCost minArr[2];
vector<ll> costPerCase;

void calcul_cost_of_case() {
  // 연결이 2개인 경우
  costPerCase.push_back(abs(aGrade[1] - bGrade[1]) + abs(aGrade[n] - bGrade[n]));
  costPerCase.push_back(abs(aGrade[1] - bGrade[n]) + abs(aGrade[n] - bGrade[1]));

  // 연결이 3개인 경우
  costPerCase.push_back(abs(aGrade[1] - bGrade[1]) + minArr[0].ofN + minArr[1].ofN);
  costPerCase.push_back(abs(aGrade[1] - bGrade[n]) + minArr[0].ofN + minArr[1].of1);
  costPerCase.push_back(abs(aGrade[n] - bGrade[1]) + minArr[0].of1 + minArr[1].ofN);
  costPerCase.push_back(abs(aGrade[n] - bGrade[n]) + minArr[0].of1 + minArr[1].of1);

  // 연결이 4개인 경우
  costPerCase.push_back(minArr[0].of1 + minArr[0].ofN + minArr[1].of1 + minArr[1].ofN);
}

void calcul_min_cost_at_end() {
  for (int i = 1; i <= n; i++) {
    minArr[0].of1 = min(minArr[0].of1, abs(aGrade[1] - bGrade[i]));
    minArr[0].ofN = min(minArr[0].ofN, abs(aGrade[n] - bGrade[i]));

    minArr[1].of1 = min(minArr[1].of1, abs(aGrade[i] - bGrade[1]));
    minArr[1].ofN = min(minArr[1].ofN, abs(aGrade[i] - bGrade[n]));
  }
}

void solve() {
  calcul_min_cost_at_end();

  calcul_cost_of_case();

  sort(costPerCase.begin(), costPerCase.end());
  
  cout << costPerCase[0] << '\n';
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> aGrade[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> bGrade[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    memset(minArr, 0x3f, sizeof(minArr));
    costPerCase.clear();

    input();
    solve();
  }

  return 0;
}

/*

[생각한 순서]

1. 문제를 한 번 다 읽었는데, 뭔 소리인지 모르겠다...

2. 문제 해석 재시도.
  - 다시 읽어본 결과, 한 컴퓨터가 고장나더라도 두 컴퓨터 열이 연결되도록 추가 연결을 해야 한다는 것.
  - 만약 추가 연결이 하나만 있다면 두 연결 지점 중 하나만 고장나더라도 문제가 발생한다.
  - 따라서 최소 2개 이상의 연결이 있어야 한 컴퓨터가 고장나더라도 문제가 없을 것 같다.
  - 그런데 한 열의 중간에서 고장나버리면 해당 열은 분단되어 버리기 때문에, 한 열의 맨끝 부분들은 반드시 반대 열과 연결되어 있어야 할 것 같다.
  - 따라서 최대 4개의 연결이 있을 것 같다.

3. 맨끝 컴퓨터을 반대 열의 한 컴퓨터와 연결시켜주는 방법.
  - 연결이 2개인 경우 : 1-1, n-n / 1-n, n-1
  - 연결이 3개인 경우 : 1-1, n-?, ?-n / 1-n, n-?, ?-1 / n-1, 1-?, ?-n / n-n, 1-?, ?-1
  - 연결이 4개인 경우 : 1-?, n-?, ?-1, ?-n

4. 각 경우에 대한 cost를 vector에 저장한 후 sort하면 될 것 같다.

5. 구현.
  - 각 경우의 cost를 저장하는 vector는 4 * (10^9 - 1)를 생각해 long long 타입으로 한다.
  - 각 열의 끝 컴퓨터마다 반대 열 중 임의의 컴퓨터까지 가는 데에 필요로 하는 최소 cost를 저장해둔다.
  - 각 경우에 대한 cost 계산을 하고 vector에 저장한다.
  - 그랬더니 cost 중에 음수가 발생했다...

6. int를 long long으로.
  - 원래는 각 연결의 최댓값이 10^9 - 1이라고 생각하여 int 범위로도 충분할 것이라 생각했다.
  - 그런데 음수가 나오는 것을 보고 long long으로 변경해주었더니 음수가 사라졌다.
  - 문제가 해결은 됐으나, 그 이유를 모르겠다...

*/
