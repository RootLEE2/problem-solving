#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 500005
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

struct grade {
  int firstExam;
  int secondExam;
  int thirdExam;

  bool operator<(const grade& o) const {
    return firstExam < o.firstExam;
  }
};

int N;
grade student[MAX_N];

int segTree[1 << 20];  // int segTree[4 * MAX_N];

void update_query(int node, int tl, int tr, int idx, int val) {
  if (idx < tl || tr < idx) return;
  if (tl == tr) {
    segTree[node] = val;
    return;
  }

  int doubleNode = node << 1;  //int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  update_query(doubleNode, tl, tm, idx, val);
  update_query(doubleNode + 1, tm + 1, tr, idx, val);

  segTree[node] = min(segTree[doubleNode], segTree[doubleNode + 1]);
}

int min_queries(int node, int tl, int tr, int l, int r) {
  if (r < l) return INF;
  if (tl == l && tr == r) return segTree[node];

  int doubleNode = node << 1;  //int doubleNode = 2 * node;
  int tm = (tl + tr) >> 1;  // int tm = (tl + tr) / 2;

  int leftChild = min_queries(doubleNode, tl, tm, l, min(tm, r));
  int rightChild = min_queries(doubleNode + 1, tm + 1, tr, max(tm + 1, l), r);

  return min(leftChild, rightChild);
}

void solve() {
  memset(segTree, 0x3f, sizeof(segTree));

  sort(student + 1, student + N + 1);

  int num = 0;

  for (int i = 1; i <= N; i++) {
    int highestRank = min_queries(1, 1, N, 1, student[i].secondExam);

    if (student[i].thirdExam < highestRank) {
      num++;
    }

    update_query(1, 1, N, student[i].secondExam, student[i].thirdExam);
  }

  cout << num;
}

void input() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int studentNum;
    cin >> studentNum;

    student[studentNum].firstExam = i;
  }

  for (int i = 1; i <= N; i++) {
    int studentNum;
    cin >> studentNum;

    student[studentNum].secondExam = i;
  }

  for (int i = 1; i <= N; i++) {
    int studentNum;
    cin >> studentNum;

    student[studentNum].thirdExam = i;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
