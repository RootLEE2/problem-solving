#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>
#include <math.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void solve()
{
	int fibo_remain[1500005];
	fibo_remain[0] = 0;
	fibo_remain[1] = 1;
	for (int i = 2; i < 1500000; i++) {
		fibo_remain[i] = (fibo_remain[i - 1] + fibo_remain[i - 2]) % 1000000;
	}

	ll n; cin >> n;

	cout << fibo_remain[n % 1500000];
}

int main()
{
	fastio;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
