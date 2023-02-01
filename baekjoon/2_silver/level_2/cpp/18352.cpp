#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF 0x3f3f3f3f

typedef long long ll;

#define MAX_N 300005

int min_dist[MAX_N];

void solve()
{
	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<int> adj_city[MAX_N];

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;

		adj_city[u].push_back(v);
	}

	memset(min_dist, 0x3f, sizeof(min_dist));
	min_dist[X] = 0;

	priority_queue<pair<int,int>> pq;
	pq.push({ 0, X });

	while (!pq.empty()) {
		int cur_cost = -pq.top().first;
		int cur_city = pq.top().second;
		pq.pop();

		for (int adj : adj_city[cur_city]) {
			if (min_dist[adj] <= cur_cost + 1)
				continue;
			
			min_dist[adj] = cur_cost + 1;
			pq.push({ -(cur_cost + 1), adj });
		}
	}

	bool flag = true;

	for (int i = 1; i <= N; i++) {
		if (min_dist[i] == K) {
			cout << i << '\n';
			flag = false;
		}
	}

	if (flag)
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