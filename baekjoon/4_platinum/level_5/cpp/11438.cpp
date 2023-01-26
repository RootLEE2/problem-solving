#include <iostream>
#include <vector>
#include <utility>
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
vector<int> adjList[MAX_N];

int depth[MAX_N];
int parent[MAX_N][LOG_N];

void set_parent(int v, int __depth)
{
	depth[v] = __depth;

	for (int adj : adjList[v]) {
		if (depth[adj] != -1)
			continue;
		
		parent[adj][0] = v;
		set_parent(adj, __depth + 1);
	}
}

void set_sparse()
{
	for (int i = 1; i < LOG_N; i++) {
		for (int v = 1; v <= N; v++) {
			if (parent[v][i - 1] == -1)
				parent[v][i] = -1;
			else
				parent[v][i] = parent[parent[v][i - 1]][i - 1];
		}
	}
}

int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	
	int diff = depth[a] - depth[b];

	for (int i = 0; diff > 0; i++, diff >>= 1) {
		if ((diff & 1) == 1)
			a = parent[a][i];
	}

	if (a == b)
		return a;

	for (int i = LOG_N - 1; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	
	return parent[a][0];
}

void solve()
{
	cin >> N;

	for (int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
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
		cout << lca(a, b) << '\n';
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