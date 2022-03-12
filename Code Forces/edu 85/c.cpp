//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 10/Apr/20 09:46:05 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 6e5 + 5;
pii arr[N];
int n;
int dp[N][2]; // previous was destroyed or not

int solve (int i, int j) {
	if (i > 2 * n) return 0;
	int& ans = dp[i][j];
	if (ans != -1) return ans;

	if (i <= n) { // we can leave it right now without destroying
		if (!j) { // previous not exploded
			ans = min (solve (i + 1, j), solve (i + 1, 1) + arr[i].ff);
		} else {
			ans = solve (i + 1, j) + max (0ll, arr[i].ff - arr[i - 1].ss);
		}
	} else { // we have to destroy it
		if (!j) {
			return 1e18;
		} else {
			ans = solve (i + 1, j) + max (0ll, arr[i].ff - arr[i - 1].ss);
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 1) {
			cin >> arr[i].ff >> arr[i].ss;
			dp[i][0] = dp[i][1] = -1;
		}
		fr (i, n + 1, 2 * n + 1) {
			arr[i] = arr[i - n];
			dp[i][0] = dp[i][1] = -1;
		}

		pr (solve (1, 0));
		fr (i, 1, 2 * n + 1) pr (dp[i]);
	}
	return 0;
}