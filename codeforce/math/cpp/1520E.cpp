/* Arranging The Sheep */
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1000006
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
vector<int> sheepLoc;

void solve() {
  int numOfSheep = sheepLoc.size();

  if (numOfSheep == 0) {
    cout << "0\n";
    return;
  }
  
  int midSheepIdx = numOfSheep >> 1;
  int midSheepLoc = sheepLoc[midSheepIdx];

  int numFromMid = numOfSheep >> 1;
  ll cnt = 0;

  for (int i = 0; i < numOfSheep; i++) {
    cnt += (ll)abs(midSheepLoc - numFromMid - sheepLoc[i]);
    numFromMid--;
  }

  cout << cnt << '\n';
}

void input() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    char character;
    cin >> character;

    if (character == '*') {
      sheepLoc.push_back(i);
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
    
    sheepLoc.clear();
  }

  return 0;
}

/*

[생각한 순서]

1. 별 사이 간격을 저장하여 최솟값 찾기?
	- 인덱스를 기반으로 계산해야 할 것 같다.
	- 따라서 입력을 받을 때 문자열이 아닌 인덱스 값을 저장하자.

2. 임의의 중심을 기반으로 양쪽 별들과의 거리 합이 최소?

3. 임의의 중심 인덱스를 찾기 위한 이분탐색?

4. 중심은 항상 양이 있는 곳인가?
	- 양이 없는 곳이 중심이 될 수 있나?
	- 아무래도 중심이 될 수 있는 양을 한 번이라도 더 움직여야 하기 때문에 아닐 것 같다.

5. 그런데 양의 수를 토대로 가장 가운데에 있는 양이 중심이지 않나?
	- 그래야 양쪽에 있는 양들을 최소로 움직일 것 같다.
	- 중심이 한 쪽으로 치우치는 순간, 그 반대쪽에 있는 양들이 움직여야 하는 거리가 증가할 뿐만 아니라 양의 수도 증가한다.

6. 양의 수가 짝수인 경우는 뭐가 가운데?
	- 생각해보면 가운데에 있는 두 양 중 어느 것이 되어도 상관 없을 것 같다.
	- 두 양 중 하나를 선택함으로써 다른 양을 향해 이동하기 위한 추가 거리는 동일하다.

7. 양이 하나도 없는 경우는?
	- 바로 0을 출력하자.

8. test 5에서 오류가 나왔다. 이유가 뭐지?
  - n이 10^6 이내이므로 최악의 경우에는 (10^6)/2 가량의 값이 계속해서 cnt에 더해질 수 있다.
  - 따라서 cnt 변수의 overflow가 원인으로 의심된다.
  - cnt의 타입형을 int에서 long long으로 변경했더니 성공했다.

*/
