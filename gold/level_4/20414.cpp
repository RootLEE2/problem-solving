#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX_N 36
#define MAX_LENGTH 100001
#define NUM_OF_ALPHABET 26
#define INF 0x3f3f3f3f
#define SQUARE(x) ((x) * (x))

int N;
map<char, pair<int, int>> rating;
string ratingHistory;

int dp[MAX_N];

void last_month_to_max(int thisMonth) {
  dp[thisMonth - 1] = rating[ratingHistory[thisMonth]].second;

  for (int i = thisMonth - 1; i > 0; i--) {
    int billingForTwoMonths = dp[i] + dp[i - 1];

    if (billingForTwoMonths < rating[ratingHistory[i]].first) {
      dp[i - 1] = rating[ratingHistory[i]].first - dp[i];
    }
    else if (rating[ratingHistory[i]].second < billingForTwoMonths) {
      dp[i - 1] = rating[ratingHistory[i]].second - dp[i];
    }
    else break;
  }
}

void estimate_billing() {
  dp[0] = (ratingHistory[0] != 'D') ? rating[ratingHistory[0]].second : rating['D'].first;

  for (int i = 1; i < ratingHistory.length(); i++) {
    char ratingThisMonth = ratingHistory[i];

    if (ratingThisMonth == 'D') {
      dp[i] = rating['D'].first;
      continue;
    }

    int billingForTwoMonths = dp[i] + dp[i - 1];

    if (billingForTwoMonths < rating[ratingThisMonth].second) {
      dp[i] = rating[ratingThisMonth].second - dp[i - 1];
    }
    else if (rating[ratingThisMonth].second < billingForTwoMonths) {
      dp[i] = 0;
      last_month_to_max(i);
    }
  }
}

void solve() {
  estimate_billing();

  int ans = 0;

  for (int i = 0; i < N; i++) {
    ans += dp[i];
  }
  cout << ans;
}

void input() {
  int s, g, p, d;

  cin >> N;
  cin >> s >> g >> p >> d;
  cin >> ratingHistory;

  rating['B'] = make_pair(0, s - 1);
  rating['S'] = make_pair(s, g - 1);
  rating['G'] = make_pair(g, p - 1);
  rating['P'] = make_pair(p, d - 1);
  rating['D'] = make_pair(d, d * 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  input();
  solve();

  return 0;
}
