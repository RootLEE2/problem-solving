#include <iostream>
#include <cstring>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f

typedef long long ll;
typedef long double ld;

void solve()
{
	char score[5];
	cin >> score;

	if (!strcmp(score, "A+"))
		cout << "4.3";
	else if (!strcmp(score, "A0"))
		cout << "4.0";
	else if (!strcmp(score, "A-"))
		cout << "3.7";
	else if (!strcmp(score, "B+"))
		cout << "3.3";
	else if (!strcmp(score, "B0"))
		cout << "3.0";
	else if (!strcmp(score, "B-"))
		cout << "2.7";
	else if (!strcmp(score, "C+"))
		cout << "2.3";
	else if (!strcmp(score, "C0"))
		cout << "2.0";
	else if (!strcmp(score, "C-"))
		cout << "1.7";
	else if (!strcmp(score, "D+"))
		cout << "1.3";
	else if (!strcmp(score, "D0"))
		cout << "1.0";
	else if (!strcmp(score, "D-"))
		cout << "0.7";
	else
		cout << "0.0";
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
