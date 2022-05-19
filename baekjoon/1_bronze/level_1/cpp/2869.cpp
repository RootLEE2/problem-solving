#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

  int A, B, V;
  cin >> A >> B >> V;
  int tmp1 = V-A, tmp2 = A-B;
  cout << (tmp1/tmp2 + (tmp1%tmp2==0 ? 1 : 2));
}