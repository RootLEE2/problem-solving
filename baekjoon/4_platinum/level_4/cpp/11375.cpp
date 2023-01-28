#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_NM 1003

int N, M;
vector<int> todo[MAX_NM];

int work2employee[MAX_NM];
bool visited[MAX_NM];

bool dfs(int employee)
{
	for (int work : todo[employee]) {
		if (visited[work])
			continue;

		visited[work] = true;

		if (work2employee[work] == 0 || dfs(work2employee[work])) {
			work2employee[work] = employee;
			return true;
		}
	}

	return false;
}

void solve()
{
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int W_i;
		cin >> W_i;

		for (int j = 0; j < W_i; j++) {
			int work_num;
			cin >> work_num;

			todo[i].push_back(work_num);
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