#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_NM 202

int N, M;
vector<int> desired_barn[MAX_NM];

int barn2cow[MAX_NM];
bool visited[MAX_NM];

bool dfs(int cow)
{
	for (int barn : desired_barn[cow]) {
		if (visited[barn])
			continue;

		visited[barn] = true;

		if (barn2cow[barn] == 0 || dfs(barn2cow[barn])) {
			barn2cow[barn] = cow;
			return true;
		}
	}

	return false;
}

void solve()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int S_i;
		cin >> S_i;

		for (int j = 0; j < S_i; j++) {
			int barn;
			cin >> barn;

			desired_barn[i].push_back(barn);
		}
	}

	int cnt = 0;

	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			cnt++;
	}

	cout << cnt;
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