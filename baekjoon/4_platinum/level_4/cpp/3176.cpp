#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_N 100005
#define LOG_N 18	// log2(100000) = 16.xxx

int N;
vector<pair<int,int>> adj_city[MAX_N];

int depth[MAX_N];
int parent[MAX_N][LOG_N];
int max_length[MAX_N][LOG_N];
int min_length[MAX_N][LOG_N];

void set_parent(int v, int __depth)
{
	depth[v] = __depth;

	for (pair<int,int> adj : adj_city[v]) {
		int u = adj.first;

		if (depth[u] != -1)
			continue;
		
		parent[u][0] = v;
		max_length[u][0] = min_length[u][0] = adj.second;

		set_parent(u, __depth + 1);
	}
}

void set_sparse()
{
	for (int i = 1; i < LOG_N; i++) {
		for (int v = 1; v <= N; v++) {
			if (parent[v][i - 1] == -1) {
				parent[v][i] = -1;
			} else {
				parent[v][i] = parent[parent[v][i - 1]][i - 1];
				min_length[v][i] = min(min_length[v][i - 1], min_length[parent[v][i - 1]][i - 1]);
				max_length[v][i] = max(max_length[v][i - 1], max_length[parent[v][i - 1]][i - 1]);
			}
		}
	}
}

pair<int,int> find_min_max_length(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	
	int diff = depth[a] - depth[b];

	pair<int,int> ret = { INF, -1 };

	for (int i = 0; diff > 0; i++, diff >>= 1) {
		if ((diff & 1) == 1) {
			ret.first = min(ret.first, min_length[a][i]);
			ret.second = max(ret.second, max_length[a][i]);
			a = parent[a][i];
		}
	}

	if (a == b)
		return ret;

	for (int i = LOG_N - 1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			ret.first = min(ret.first, min_length[a][i]);
			ret.second = max(ret.second, max_length[a][i]);

			ret.first = min(ret.first, min_length[b][i]);
			ret.second = max(ret.second, max_length[b][i]);

			a = parent[a][i];
			b = parent[b][i];
		}
	}

	ret.first = min(ret.first, min_length[a][0]);
	ret.second = max(ret.second, max_length[a][0]);

	ret.first = min(ret.first, min_length[b][0]);
	ret.second = max(ret.second, max_length[b][0]);
	
	return ret;
}

void solve()
{
	cin >> N;

	for (int i = 1; i < N; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		adj_city[u].push_back({ v, l });
		adj_city[v].push_back({ u, l });
	}

	memset(depth, -1, sizeof(depth));

	parent[1][0] = -1;
	set_parent(1, 0);
	set_sparse();

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		pair<int,int> res = find_min_max_length(a, b);
		cout << res.first << ' ' << res.second << '\n';
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