#include <iostream>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void solve()
{
	char str[1003];
	cin >> str;

	cout << str[0] << str[strlen(str) - 1] << '\n';
}

int main()
{
	fastio;

	int t = 1;
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}