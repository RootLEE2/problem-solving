#include <iostream>
using namespace std;

struct Comp {
  int root;
  int num;
};

Comp C[1000001];

int find(int a) {
  if(C[a].root == a)
    return a;
  return C[a].root = find(C[a].root);
}

int main() {
  cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

  int N, a, b, c;
  char inst;
  int rootA, rootB;

  for (int i = 1; i < 1000001; i++) {
		C[i].root = i;
		C[i].num = 1;
	}

  cin >> N;
  while (N--) {
    cin >> inst;
    if (inst == 'I') {
      cin >> a >> b;
      rootA = find(a);
      rootB = find(b);

      if(rootA != rootB){
        C[rootB].root = rootA;
        C[rootA].num += C[rootB].num;
        C[rootB].num = 0;
      }
    }
    else {
      cin >> c;
      cout << C[find(c)].num << '\n';
    }
  }
}