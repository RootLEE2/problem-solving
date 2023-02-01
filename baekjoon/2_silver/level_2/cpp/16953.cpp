#include <iostream>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF 0x3f3f3f3f

typedef long long ll;

void solve()
{
	int A, B;
	cin >> A >> B;

	queue<pair<ll,int>> q;
	q.push({ A, 1 });

	while (!q.empty()) {
		ll val = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (B < val) {
			continue;
		} else if (B == val) {
			cout << cnt;
			return;
		}

		q.push({ val * 2, cnt + 1 });
		q.push({ val * 10 + 1, cnt + 1 });
	}

	cout << -1;
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