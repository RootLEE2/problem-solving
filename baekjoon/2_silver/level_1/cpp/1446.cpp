#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF 0x3f3f3f3f

typedef long long ll;

#define MAX_D 10004

void solve()
{
	int N, D;
	cin >> N >> D;

	vector<pair<int,int>> shortcut[MAX_D];

	for (int i = 0; i < N; i++) {
		int s, e, l;
		cin >> s >> e >> l;

		shortcut[s].push_back({ e, l });
	}

	priority_queue<pair<int,int>> pq;
	pq.push({ 0, 0 });

	int min_length[MAX_D];
	memset(min_length, 0x3f, sizeof(min_length));
	min_length[0] = 0;

	while (!pq.empty()) {
		int cur_length = -pq.top().first;
		int cur_loc = pq.top().second;
		pq.pop();

		if (D < cur_loc)
			continue;
		
		for (pair<int,int> s : shortcut[cur_loc]) {
			if (min_length[s.first] <= cur_length + s.second)
				continue;
			min_length[s.first] = cur_length + s.second;
			pq.push({ -(cur_length + s.second), s.first });
		}

		if (cur_length + 1 < min_length[cur_loc + 1]) {
			min_length[cur_loc + 1] = cur_length + 1;
			pq.push({ -(cur_length + 1), cur_loc + 1 });
		}
	}

	cout << min_length[D];
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