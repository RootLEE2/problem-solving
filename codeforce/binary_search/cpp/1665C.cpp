/* Tree Infection */
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

int n;
int numOfChild[MAX_N];

int numOfParent;
int injectionTime;
int spreadingTime;

bool compare(int a, int b) {
  return a > b;
}

int calcul_extra_time() {
  vector<int> remainChild;

  for (int i = 0; i < numOfParent; i++) {
    int temp = i + numOfChild[i] - injectionTime;
    
    if (0 < temp) {
      remainChild.push_back(temp);
    }
  }
  
  int left = 0;
  int right = spreadingTime - injectionTime;
  int minTime = right;

  while (left <= right) {
    int mid = (left + right) >> 1;

    int expectedInjectionTime = 0;
    for (int remainTime : remainChild) {
      if (mid < remainTime) {
        expectedInjectionTime += remainTime - mid;
      }
    }

    if (mid < expectedInjectionTime) {
      left = mid + 1;
    } else {
      minTime = min(minTime, mid);
      right = mid - 1;
    }
  }

  return minTime;
}

void calcul_base_time() {
  numOfParent = 1;
  injectionTime = 2;  // root + 0th of numOfChild
  spreadingTime = numOfChild[0];

  for (int i = 1; i < n; i++) {
    if (numOfChild[i] == 0) break;

    spreadingTime = max(spreadingTime, i + numOfChild[i]);
    injectionTime++;
    numOfParent++;
  }
}

void solve() {
  sort(numOfChild, numOfChild + n + 1, compare);

  calcul_base_time();

  int ans = injectionTime;
  
  if (injectionTime < spreadingTime) {
    ans += calcul_extra_time();
  }
  
  cout << ans << '\n';
}

void input() {
  cin >> n;

  for (int i = 1; i < n; i++) {
    int ancestorOfIth;
    cin >> ancestorOfIth;

    numOfChild[ancestorOfIth]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;

  for (cin >> t; t > 0; t--) {
    input();
    solve();

    memset(numOfChild, 0, (n + 1) * sizeof(int));
  }

  return 0;
}

/*

[생각한 순서]

1. 입력값을 보는 순간.
  - Disjoint Set과 Union-Find?
  - n의 값인 2 * 10^6에서 *2 때문에 특정 자료구조가 있는 것 같은 느낌이 들지만 난 모르겠다.

2. 입력값을 보고 생각한 변수 기본 세팅 아이디어.
  - vector에 자식 vertex 번호를 저장?
  - 자식들에게 질병을 퍼뜨리기 위해서는 자식 중 임의의 하나를 감염시키는 것이 먼저이다.
  - array 형식으로 자식의 개수를 저장?
  - 자식 하나가 감염됐을 때 퍼지는 데에 걸리는 시간을 계산할 수 있어진다.

3. 전염되는 원리.
  - 공통된 부모를 가지는 vertex끼리만 전염이 된다.
  - 따라서 child의 수가 가장 많은 곳이 모두 전염되는 데에 가장 오랜 시간이 걸린다.
  - 각 부모의 child들 하나씩 모두 감염시키고도 모두 전염되는 데에 시간이 남는다면 전염되야 하는 vertex를 감염시킨다.
  - 따라서 감염시켜야 하는 vertex의 수가 중요하지 않을까...
  - 반드시 감염시켜야 하는 vertex의 수는 부모의 수 + 1(root 포함)과 같다.

4. 질병이 퍼지는 데에 걸리는 시간 계산.
  - 전염되는 데에 걸리는 최대 시간이 반드시 감염되어야 하는 vertex의 감염 시간(부모의 수 + 1)보다 짧다면 그대로 출력해준다.
  - 그게 아니라면 최대 전염 시간에서 감염 시간을 빼고, 해당 값을 2로 나눈 몫과 나머지를 더해준다.

5. test 6에서 오류가 나왔다. 이유가 뭐지?
  - 최대 전염 시간이 감염 시간보다 큰 경우에 문제가 발생하는 것 같다.
  - 최대 전염 시간인 경우가 해결되더라도 다른 전염 시간이 남아 있을 수 있다.
  - 따라서 이를 해결하기 위해 이분탐색을 통해 mid 값을 전염 및 감염 시간으로 생각하고 가능한 시나리오인지 확인한다.
  - 그런데 틀렸다...

6. 오류 해결 시도.
  - 틀린 이유를 고민해보다가 다시 그래프를 그리면서 코드를 봤다.
  - 그런데 calcul_extra_time()에서 remainChild를 구해줄 때 i를 안 더했다...
  - 즉 전염시키는 시간을 구할 때 감염되기 위해 기다리는 시간을 안 더했다.
  - i를 더해주니 정답 처리 됐다.

*/
