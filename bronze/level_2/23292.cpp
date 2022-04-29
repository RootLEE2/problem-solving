#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 1000
#define MAX_LENGTH 101
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

string birth;
int N;
string codingDay[MAX_N];

int square_of_difference(int num1, int num2) {
  return SQUARE(num1 - num2);
}

int calcul_rythm(string __codingDay) {
  int dateFormatLength = 3;
  int dateFormatEndIdx[] = { 4, 6, 8 };

  int rythm = 1;
  int idx = 0;
  
  for (int i = 0; i < dateFormatLength; i++) {
    int temp = 0;

    for (; idx < dateFormatEndIdx[i]; idx++) {
      temp += square_of_difference((int)birth[idx], (int)__codingDay[idx]);
    }

    rythm *= temp;
  }

  return rythm;
}

void solve() {
  sort(codingDay, codingDay + N);

  int maxRythm = -1, idxOfMax;

  for (int i = 0; i < N; i++) {
    int bioRythm = calcul_rythm(codingDay[i]);

    if (maxRythm < bioRythm) {
      maxRythm = bioRythm;
      idxOfMax = i;
    }
  }

  cout << codingDay[idxOfMax];
}

void input() {
  cin >> birth;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> codingDay[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
