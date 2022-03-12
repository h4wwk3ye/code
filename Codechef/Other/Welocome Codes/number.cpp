//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Jan/20 10:13:05 PM
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

int n, k;
const int N = 1e6 + 5;
int dp[N];

int solve (int i) {
	pr (i);
	if (i == 1) return 0;
	if (i > 2 * n) return dp[i] = 1e18;
	int& ans = dp[i];
	if (ans != -1) return ans;

	if (i % k == 0) {
		ans = 1 + solve (i / k);
	} else if (i > k) {
		ans = 1 + min (solve (i - 1), solve (i + 1));
	} else {
		ans = i - 1;
	}
	return ans;
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		fr (i, 0, 2 * n + 1000) dp[i] = -1;
		if (k == 1) {
			pr (n - 1);
			continue;
		}
		int ans = solve (n);
		pr (ans);
	}
	return 0;
}