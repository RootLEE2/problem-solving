#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 200000
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N;
pair<int, int> board[MAX_N];

vector<pair<int, int>> connectedBoard;

int find_max_point() {
  int maxR = 0;
  int idxOfMax;

  for (int i = 0; i < connectedBoard.size(); i++) {
    if (connectedBoard[i].first <= maxR) {
      idxOfMax = i;

      int canJump = connectedBoard[i].second - connectedBoard[i].first;
      maxR = max(maxR, connectedBoard[i].second + canJump);
    }
  }

  return connectedBoard[idxOfMax].second;
}

void connect_board() {
  int start = 0;
  int end = 0;

  for (int i = 0; i < N; i++) {
    if (end < board[i].first) {
      connectedBoard.push_back(make_pair(start, end));

      start = board[i].first;
      end = board[i].second;
    }
    else {
      end = max(end, board[i].second);
    }
  }
  connectedBoard.push_back(make_pair(start, end));
}

void solve() {
  sort(board, board + N);

  connect_board();

  cout << find_max_point();
}

void input() {
  int L, R;
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> L >> R;

    board[i] = make_pair(L, R);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
