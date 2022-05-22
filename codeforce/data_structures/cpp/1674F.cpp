/**
 * @ref https://www.acmicpc.net/blog/view/21
 * @ref https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/09/algorithm-fenwick-tree/
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
#define MAX_NM 1003
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

int n, m, q;
char desktop[MAX_NM][MAX_NM];

int numOfIcon;
int fenwickTree[MAX_NM][MAX_NM];

int sum_queries(int r, int c) {
  int sum = 0;

  for (int i = r; i > 0; i -= i & -i) {
    for (int j = c; j > 0; j -= j & -j) {
      sum += fenwickTree[i][j];
    }
  }

  return sum;
}

int get_num_of_moving_icon() {
  if (numOfIcon == 0) return 0;

  int lastRow;
  int lastCol;
  bool flag;

  if (numOfIcon % n == 0) {
    flag = false;

    lastRow = n;
    lastCol = numOfIcon / n;
  } else {
    flag = true;

    lastRow = numOfIcon % n;
    lastCol = numOfIcon / n + 1;
  }

  int numOfIconAlreadyIn = sum_queries(lastRow, lastCol);

  if (flag) {
    numOfIconAlreadyIn += sum_queries(n, lastCol - 1) - sum_queries(lastRow, lastCol - 1);
  }

  return numOfIcon - numOfIconAlreadyIn;
}

void update_query(int r, int c, int delta) {
  numOfIcon += delta;
  
  for (int i = r; i <= n; i += i & -i) {
    for (int j = c; j <= m; j += j & -j) {
      fenwickTree[i][j] += delta;
    }
  }
}

void remove_or_appear_icon(int r, int c) {
  if (desktop[r][c] == '*') {
    desktop[r][c] = '.';
    update_query(r, c, -1);
  }
  else if (desktop[r][c] == '.') {
    desktop[r][c] = '*';
    update_query(r, c, 1);
  }
}

void solve() {
  for (int i = 0; i < q; i++) {
    int x, y;
    cin >> x >> y;

    remove_or_appear_icon(x, y);

    cout << get_num_of_moving_icon() << '\n';
  }
}

void input() {
  cin >> n >> m >> q;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> desktop[i][j];

      if (desktop[i][j] == '*') {
        update_query(i, j, 1);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}

/*

[생각한 순서]

1. 이번 문제 역시 해석이 안된다...
  - 다른 사람의 해석을 보고 겨우 이해했다.

2. 입력을 어떻게 처리해야 할까?
  - 문자열 배열로 아이콘 상태를 저장한다.
  - 각 행에 있는 아이콘의 개수를 저장한다?

3. 시간제한 고려.
  - 시간제한을 생각했을 때 한 쿼리를 n 혹은 log(n) 정도로 해결해야 할 것 같다.
  - 따라서 트리 구조 같은 것을 사용해야 시간 초과가 없을 것 같다.

4. 좌측 상단 정렬을 하기 위한 방법은?
  - 행과 열의 합을 이용해 가장 멀리 있는 아이콘을 먼저 이동시킨다?
  - 움직이지 않아도 될 아이콘을 어떻게 찾아야 할까?
  - 행이 커질수록 아이콘의 개수는 줄어들거나 같을 것이다.
  - 그러면 모든 아이콘들을 가장 왼쪽으로 몰아두고 시작한다고 생각해도 되지 않을까?

5. 갑자기 생각난 다른 방법.
  - 결국 아이콘을 좌측 상단부터 배치시킨다면 아이콘의 개수를 알고 있을 때 마지막 아이콘이 위치할 좌표를 알 수 있다.
  - 그리고 정답은 아이콘의 개수에다가 정렬됐을 때 만들어지는 모양 안에 이미 위치해 있는 아이콘의 개수를 빼준 것이다.
  - 그렇다면 정렬됐을 때 만들어지는 모양 안에 이미 위치해 있는 아이콘의 개수만 쉽게 구할 수 있으면 된다.
  - 아이콘의 개수만큼 단순 반복문으로 정렬 예상 좌표들을 다 확인한다면 시간 초과가 나는 경우가 있을 것 같다.
  - 정렬했을 때 마지막 아이콘이 위치할 좌표는 계산할 수 있으니, 해당 좌표로 누적합을 구할 수 있게끔 배열을 만들면 되지 않을까?
  - 그런데 2차원 배열 형식으로 저장하면 아이콘에 대한 갱신이 이루어졌을 때 연산 횟수가 많아 시간 초과가 발생할 수 있을 것 같다.
  - 다른 자료구조가 생각나지 않아 일단 2차원 배열로 구현해야 할 것 같다.

6. 마지막 아이콘의 좌표 계산.
  - 전체 아이콘의 개수는 결국 (행의 크기, 이하 r) * (열의 개수, 이하 c) + (나머지 행의 개수, 이하 t)이다.
  - 따라서 t가 0인 경우, 즉 아이콘의 개수가 r의 값인 n으로 나누어떨어진다면 마지막 아이콘의 좌표는 (r, c)가 될 것이다.
  - t가 0이 아닌 경우의 마지막 아이콘의 좌표는 (t, c + 1)이 될 것이다.
  - 그리고 아이콘의 개수가 n으로 나누어떨어지지 않는다면 다 채워진 열들 옆에 덜 채워진 한 열이 더 있는 것이기 때문에 마지막 아이콘 좌표를 토대로 추가적인 누적합을 더해주어야 한다.

7. 역시나 test 8에서 시간 초과가 발생했다.
  - 세그먼트 트리를 행 크기만큼 만들어서 구현해야 하나 싶다.
  - 2차원 배열을 업데이트하는 데에 O(N), 합을 구하는 데에 O(1)이다.
  - 하지만 트리를 사용하게 되면 둘 다 O(log(N))쯤이 될 테니 적합한 트리 구조를 찾아야 할 것 같다.
  - 평소에 세그먼트 트리 문제를 풀면서 많이 본 펜윅 트리가 생각나 어떤 트리인지 알아봤다.
  - 세그먼트 트리와 비교했을 때 적은 공간 복잡도를 가진다는 것을 알게 되었는데, 이번 기회에 공부하여 사용해 보기로 했다.
  - 펜윅 트리를 공부하다 보니 평소에 자주 만나던 "i & -i"가 i의 LSB를 구하는 것이라는 것도 알게 되었다.

8. 펜윅 트리 적용.
  - 빠르게 펜윅 트리에 대해 공부해 보았지만 이번 문제는 2차원 배열이라 습득이 쉽지는 않았다.
  - 2차원 배열의 펜윅 트리를 완벽히 이해하지는 못하였지만 어쨌든 펜윅 트리를 적용했더니 통과되었다.
  - 펜윅 트리에 대한 추가 공부가 필요할 것 같다.

*/
