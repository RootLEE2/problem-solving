/**
 * @ref Knapsack https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1003
#define MAX_CAPACITY 12003
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
int b[MAX_N];
int c[MAX_N];

int minNumOfOperation[MAX_N];

int knapsack_for_max_coin() {
  const int MIN_K = min(k, 12000);

  int dp[MIN_K + 1];
  memset(dp, 0, sizeof(dp));

  for (int i = 1; i <= n; i++) {
    int numOfBi = minNumOfOperation[b[i]];

    for (int num = MIN_K; num >= 0; num--) {
      if (numOfBi <= num) {
        dp[num] = max(dp[num], dp[num - numOfBi] + c[i]);
      }
    }
  }

  return dp[MIN_K];
}

void bfs_for_min_num_of_operations() {
  queue<int> q;
  q.push(1);
  minNumOfOperation[1] = 0;

  while (!q.empty()) {
    int a_i = q.front();
    q.pop();

    for (int x = 1; x <= a_i; x++) {
      int afterOperation = a_i + a_i / x;

      if (1000 < afterOperation) continue;

      if (minNumOfOperation[a_i] + 1 < minNumOfOperation[afterOperation]) {
        minNumOfOperation[afterOperation] = minNumOfOperation[a_i] + 1;
        q.push(afterOperation);
      }
    }
  }
}

void solve() {
  cout << knapsack_for_max_coin() << '\n';
}

void input() {
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  memset(minNumOfOperation, 0x3f, sizeof(minNumOfOperation));
  bfs_for_min_num_of_operations();

  int t;
  for (cin >> t; t > 0; t--) {
    input();
    solve();
  }

  return 0;
}

/*

[생각한 순서]

1. a_i가 커지는 방법.
  - 처음에는 x가 1이어야 a_i가 2가 될 수 있다.
  - 그 이후로는 1 또는 2일 때 값이 4 또는 3이 된다.

2. 입력 조건 분석.
  - b_i의 최댓값이 1000이다.
  - 모든 b_i에 대해 해당 값이 되는 데에 걸리는 연산 횟수를 계산하면 되지 않을까?
  - 그렇다면 a_i가 1000까지 커지는 데에 최소 얼마가 걸릴까?
  - n이 작지만 시간제한이 2초인 것으로 보아 b_i까지의 연산 횟수를 구하는 게 힘들 것 같다.
  - BFS를 써서 구해야 하나...
  - 모든 b_i에 대한 연산 횟수를 구하면 knapsack algorithm으로 문제를 해결할 수 있을 것 같다.
  - b_i의 최대 연산 횟수는 (b_i - 1)이다.
  - 그렇다면 최소 연산 횟수를 구했을 때, 최대와 최소 사이 모든 횟수로 b_i를 만들 수 있음이 보장되는가?
  - b_i를 10으로 두어 계산해 봤는데, 최소 횟수 4번부터 최대 횟수 9번까지 모두 만들 수 있었다.
  - 따라서 위 의문이 보장되는 것 같고, 이제 b_i의 최소 연산 횟수만 구하면 된다.

3. b_i의 최소 연산 횟수.
  - BFS로 모든 경우를 다 돌아보는 것 말고는 생각이 나지 않기에 BFS로 구현해 보고자 한다.
  - b_i의 최소 연산 횟수를 구하는 과정은 동일하기 때문에 하나의 배열에 모든 값에 대한 최소 연산 횟수를 저장해두고, 나중에 계산할 때 가져다가 사용하는 방식으로 하면 될 것 같다.
  - 원래는 각 케이스의 b_i 중 가장 큰 값까지 매번 계산하여 사용할 생각이었는데, 모든 케이스 입력을 시작하기 전에 1000까지의 최소 연산 횟수를 계산해두면 다시 계산할 필요가 없지 않을까?

4. knapsack algorithm 사용.
  - 배낭의 cost 허용 최댓값이 1,000,000으로 너무 크다.
  - b_i가 1000일 때 최소 연산 횟수와 n의 최댓값의 곱셈 결괏값을 사용하면 배열 크기를 줄일 수 있을 것 같다.
  - 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> 128 -> 256 -> 512 -> 768 -> 960 -> 1000
  - b_i가 1000일 때의 최소 연산 횟수는 12이므로, 12000만큼만 만들면 된다.
  - 그런데 배열을 줄여서 만들더라도 for 문 반복 횟수가 너무 많은 것 같아 재귀로 구현해 봤다.

5. test 2에서의 시간 초과.
  - knapsack을 재귀로 구현하면 시간 초과가 발생하는 건가..?
  - 생각해 보니 O(2^n)인 knapsack으로 풀었다...
  - dp로 다시 풀어야겠다.
  - dp로 새로 제출하니 정답 처리 되었다.

*/
