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
	int N;
	cin >> N;

	priority_queue<int> pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp;
			cin >> tmp;

			pq.push(-tmp);
		}

		while (pq.size() > N) {
			pq.pop();
		}
	}

	cout << -pq.top();
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