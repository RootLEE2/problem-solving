#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

#define MAX_N 1000006

void solve()
{
	int N;
	cin >> N;

	int A[MAX_N];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	vector<int> tmp_seq;
	int index_seq[MAX_N];

	for (int i = 1; i <= N; i++) {
		int A_i = A[i];

		if (tmp_seq.empty() || tmp_seq.back() < A_i) {
			index_seq[i] = tmp_seq.size();
			tmp_seq.push_back(A_i);
			continue;
		}

		vector<int>::iterator low = lower_bound(tmp_seq.begin(), tmp_seq.end(), A_i);
		*low = A_i;
		index_seq[i] = low - tmp_seq.begin();
	}

	vector<int> longest_seq;
	int cur_index = tmp_seq.size() - 1;

	for (int i = N; i > 0; i--) {
		if (index_seq[i] == cur_index) {
			cur_index--;
			longest_seq.push_back(A[i]);
		}
	}
	reverse(longest_seq.begin(), longest_seq.end());

	cout << longest_seq.size() << '\n';
	for (int e : longest_seq)
		cout << e << ' ';
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
