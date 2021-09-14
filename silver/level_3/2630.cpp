// ver.1  2084MB
#include <iostream>
using namespace std;
#define MAX_N 128

int paper[MAX_N][MAX_N];
int cnt[2];

void div_conq(int x, int y, int size) {
  int temp = 0;
  for (int i = x; i < x+size; i++) {
    for (int j = y; j < y+size; j++) {
      if (paper[i][j] == 1) {
        temp++;
      }
    }
  }

  if (temp == 0) { cnt[0]++; }
  else if (temp == size*size) { cnt[1]++; }
  else {
    temp = size/2;
    div_conq(x, y, temp);
    div_conq(x+temp, y, temp);
    div_conq(x, y+temp, temp);
    div_conq(x+temp, y+temp, temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  div_conq(0, 0, N);
  cout << cnt[0] << '\n' << cnt[1];

  return 0;
}


// ver.2  2084MB
#include <iostream>
using namespace std;
#define MAX_N 128

int paper[MAX_N][MAX_N];
int white, blue;

void div_conq(int x, int y, int size) {
  bool isWhite = false, isBlue = false;
  for (int i = x; i < x+size; i++) {
    for (int j = y; j < y+size; j++) {
      if (paper[i][j] == 1) { isBlue = true; }
      else { isWhite = true; }
      if (isWhite && isBlue) { break; }
    }
  }

  if (!isWhite) { blue++; }
  else if (!isBlue) { white++; }
  else {
    int temp = size/2;
    div_conq(x, y, temp);
    div_conq(x+temp, y, temp);
    div_conq(x, y+temp, temp);
    div_conq(x+temp, y+temp, temp);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> paper[i][j];
    }
  }

  div_conq(0, 0, N);
  cout << white << '\n' << blue;

  return 0;
}
