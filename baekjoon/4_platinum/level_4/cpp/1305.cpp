#include <iostream>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_L 1000006

void solve()
{
	int L;
	char billboard[MAX_L];

	cin >> L;
	cin >> billboard;

	int failFunc[MAX_L];
	for (int pos = 1, cnt = 0; pos < L; pos++) {
		while (cnt > 0 && billboard[pos] != billboard[cnt])
			cnt = failFunc[cnt - 1];
		if (billboard[pos] == billboard[cnt])
			failFunc[pos] = ++cnt;
	}

	cout << L - failFunc[L - 1];
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