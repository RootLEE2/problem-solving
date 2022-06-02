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

int n;
int a[MAX_N];
int b[MAX_N];

int storedA[MAX_N];

void solve() {
  int idxOfA = n;
  int idxOfB = n;

  while (0 < idxOfB) {
    int a_i = a[idxOfA];
    int b_i = b[idxOfB];

    if (a_i == b_i) {
      idxOfB--;

      while (a_i == b[idxOfB]) {
        storedA[a_i]++;
        idxOfB--;
      }

      idxOfA--;
      continue;
    }

    if (0 < storedA[a_i]) {
      storedA[a_i]--;
      idxOfA--;
      continue;
    }

    cout << "NO\n";
    return;
  }

  cout << "YES\n";
}

void input() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  for (cin >> t; t > 0; t--) {
    memset(storedA, 0, sizeof(storedA));
    
    input();
    solve();
  }

  return 0;
}

/*

[생각한 순서]

1. 문제만 봤을 때는 아무런 아이디어가 안 떠오른다...

2. 예제 분석.
  - a나 b의 시작에 같은 값들이 2개 이상 있으면 안 될 확률이 높다.
  - b을 입력받을 때, 앞에서부터 어떤 값이 몇 개씩 있는지 차례대로 저장하는 건 어떨까?
  - a_i 별로 a_i 값이 있는 인덱스를 vector에 저장한다? (인접 리스트처럼)
  - 위 방법은 값 하나를 뒤로 넘길 때마다 전체 vector를 다 확인해야 하므로 안 될 것 같다.
  - a_i와 b_i의 값이 같지 않으면 a_i를 vector 같은 배열에 넣고 넘긴다. 그러고 나서 뒤에 있는 값들로 넘어가던 중 같은 값이 있다면 그 값 뒤에 넣는다?

3. 발상의 전환.
  - 주어진 operation을 수행하면 앞에 있는 값이 뒤로 간다.
  - 지금까지 생각해 봤을 때 값을 앞에서 뒤로 넘기면 인덱스를 계산하기 힘들다는 것이 가장 큰 문제였지 않나?
  - 그렇다면 뒤에서부터 시작한다면?
  - 뒤에서부터 값을 비교하되, a_i와 b_i의 값이 다르면 값을 저장해두는 배열을 먼저 확인한다.
  - 해당 배열 안에 현재 a_i 값이 있으면 해당 값을 뺀다.
  - 현재 a_i 값이 없다면 이전 b_i 값과 현재 b_i 값과 비교한다.
  - 만약에 두 값이 같다면 현재 b_i 값을 배열에 저장한다.
  - 두 값이 다르다면 불가능한 경우이다.

4. 구현.
  - a_i 값을 저장해두는 변수를 vector가 아니라 n 크기의 배열 형식으로 저장해두면 시간이 덜 걸릴 것 같다.
  - b를 마지막부터 처음까지 다 확인했을 때 남아있는 a는 주어진 operation을 수행하는 영역이기 때문에 굳이 반복문으로 확인할 필요가 없다.

5. test 2에서 틀렸다.
  - 어떤 경우가 있는 건지 모르겠다...
  - 지금까지 나온 a_i의 개수를 저장해서 나중에 a_i와 b_j가 다른 경우 차감하기..? 틀렸다...
  - 앞으로 나와야 하는 a_i의 개수를 세서 저장해두기..? 맞았다!!

*/
