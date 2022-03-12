/*
				C++
				encoding: UTF-8
				Modified: <09/Aug/2019 04:19:39 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on
int n, m, k;
int arr[25];
int cost[25][25], rating[25][25];
// ve< ve< int > > cost, rating;
int dp[25][1005][2];

int solve (int i, int money, int j) { // i - batch, money remaining, j - seal open or closed
	if (i == n) return 0;

	int& ans = dp[i][money][j];

	if (ans != -1) return ans;

	int curr = 0;
	int dont_open = solve (i + 1, money, 0);

	if (arr[i] <= money and j == 0) { // money more than seal cost and seal is closed
		money -= arr[i];
		fr (x, 0, m) {
			if (cost[i][x] <= money) {
				curr = max (curr, rating[i][x] + solve (i, money - cost[i][x], 1));
			}
		}
		money += arr[i];
	} else if (j == 1) { // seal already openend
		fr (x, 0, m) {
			if (cost[i][x] <= money) {
				curr = max (curr, rating[i][x] + solve (i, money - cost[i][x], 1));
			}
		}
	}
	ans = max (dont_open, curr);
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, -1);
		cin >> n >> m >> k;
		// arr.resize (n);
		// cost.resize (n, ve< int > (m, 0));
		// rating.resize (n, ve< int > (m, 0));

		fr (i, 0, n) cin >> arr[i];
		fr (i, 0, n) fr (j, 0, m) cin >> cost[i][j];
		fr (i, 0, n) fr (j, 0, m) cin >> rating[i][j];

		int ans = solve (0, k, 0);
		cout << ans << endl;
	}
	return 0;
}
