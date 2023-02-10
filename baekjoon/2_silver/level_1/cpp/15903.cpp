#include <iostream>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void solve()
{
	int n, m;
	cin >> n >> m;

	priority_queue<ll> pq;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		pq.push(-a);
	}

	for (int i = 0; i < m; i++) {
		ll a, b;
		a = -pq.top();
		pq.pop();
		b = -pq.top();
		pq.pop();

		pq.push(-(a+b));
		pq.push(-(a+b));
	}

	ll sum = 0;

	for (int i = 0; i < n; i++) {
		sum += -pq.top();
		pq.pop();
	}

	cout << sum;
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