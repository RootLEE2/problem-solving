#include <iostream>
#include <vector>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void __init_parent(int *parent, int count)
{
	for (int i = 1; i <= count; i++) {
		parent[i] = i;
	}
}

int __find_parent(int *parent, int a)
{
	if (parent[a] == a) return a;
	else return parent[a] = __find_parent(parent, parent[a]);
}

void __union_parent(int *parent, int a, int b)
{
	parent[__find_parent(parent, b)] = __find_parent(parent, a);
}

bool __same_parent(int *parent, int a, int b)
{
	return ((__find_parent(parent, a) == __find_parent(parent, b)) ? true : false);
}

void solve()
{
#define MAX_N 51
#define MAX_M 51
	int N, M;
	cin >> N >> M;

	int num_truth;
	cin >> num_truth;

	vector<int> someone_knows;

	for (int i = 0; i < num_truth; i++) {
		int people;
		cin >> people;

		someone_knows.push_back(people);
	}

	int parent[MAX_N];

	__init_parent(parent, N);

	vector<int> party_people[MAX_M];

	for (int i = 0; i < M; i++) {
		int num_people;
		cin >> num_people;

		int first_people;
		cin >> first_people;
		party_people[i].push_back(first_people);

		for (int j = 1; j < num_people; j++) {
			int people;
			cin >> people;
			party_people[i].push_back(people);

			__union_parent(parent, first_people, people);
		}
	}

	int cnt = M;

	for (int i = 0; i < M; i++) {
		for (int in_party : party_people[i]) {
			bool flag = false;

			for (int known : someone_knows) {
				if (__same_parent(parent, in_party, known)) {
					flag = true;
					break;
				}
			}

			if (flag) {
				cnt--;
				break;
			}
		}
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