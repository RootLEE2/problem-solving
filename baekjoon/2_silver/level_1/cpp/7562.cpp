#include <iostream>
#include <queue>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF 0x3f3f3f3f

typedef long long ll;

#define MAX_L 302

void solve()
{
	int l;
	pair<int,int> cur_knight;
	pair<int,int> target_knight;

	cin >> l;
	cin >> cur_knight.first >> cur_knight.second;
	cin >> target_knight.first >> target_knight.second;

	queue<pair<pair<int,int>,int>> q;
	q.push({ cur_knight, 0 });

	bool visited[MAX_L][MAX_L] = { false };
	visited[cur_knight.first][cur_knight.second] = true;

	int r_knight_movement[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int c_knight_movement[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	while (!q.empty()) {
		pair<int,int> knight_pos = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (knight_pos.first == target_knight.first && knight_pos.second == target_knight.second) {
			cout << cnt << '\n';
			return;
		}

		for (int i = 0; i < 8; i++) {
			int r_next_knight = knight_pos.first + r_knight_movement[i];
			int c_next_knight = knight_pos.second + c_knight_movement[i];

			if (r_next_knight < 0 || l <= r_next_knight || c_next_knight < 0 || l <= c_next_knight)
				continue;
			if (visited[r_next_knight][c_next_knight])
				continue;

			visited[r_next_knight][c_next_knight] = true;
			q.push({ { r_next_knight, c_next_knight }, cnt + 1 });
		}
	}
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