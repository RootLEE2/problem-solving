#include <iostream>
#include <utility>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define INF 0x3f3f3f3f

typedef long long ll;

pair<int,int> tree_node[30];

void preorder(int node)
{
	cout << (char)(node + 'A');
	if (0 <= tree_node[node].first)
		preorder(tree_node[node].first);
	if (0 <= tree_node[node].second)
		preorder(tree_node[node].second);
}

void inorder(int node)
{
	if (0 <= tree_node[node].first)
		inorder(tree_node[node].first);
	cout << (char)(node + 'A');
	if (0 <= tree_node[node].second)
		inorder(tree_node[node].second);
}

void postorder(int node)
{
	if (0 <= tree_node[node].first)
		postorder(tree_node[node].first);
	if (0 <= tree_node[node].second)
		postorder(tree_node[node].second);
	cout << (char)(node + 'A');
}

void solve()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		char node, left, right;
		cin >> node >> left >> right;

		tree_node[node - 'A'].first = left - 'A';
		tree_node[node - 'A'].second = right - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
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