#include <iostream>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void solve()
{
	char str[102], *result;

	while ((result = fgets(str, sizeof(str), stdin)) != NULL) {
		cout << str;
	}
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
