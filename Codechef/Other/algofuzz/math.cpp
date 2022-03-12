//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/Nov/19 10:29:58 PM
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

const int N = 1e6 + 5;
int dp[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 1;
	dp[5] = 1;
	fr (i, 6, N) {
		if (i % 2 == 0 and i % 3 == 0 and i % 5 == 0) {
			dp[i] =
			min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], min (dp[i / 2], min (dp[i / 3], dp[i / 5]))))) + 1;
		} else if (i % 2 == 0 and i % 3 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], min (dp[i / 2], dp[i / 3])))) + 1;
		} else if (i % 2 == 0 and i % 5 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], min (dp[i / 2], dp[i / 5])))) + 1;
		} else if (i % 3 == 0 and i % 5 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], min (dp[i / 5], dp[i / 3])))) + 1;
		} else if (i % 2 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], dp[i / 2]))) + 1;
		} else if (i % 3 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], dp[i / 3]))) + 1;
		} else if (i % 5 == 0) {
			dp[i] = min (dp[i - 2], min (dp[i - 3], min (dp[i - 5], dp[i / 5]))) + 1;
		} else {
			dp[i] = min (dp[i - 2], min (dp[i - 3], dp[i - 5])) + 1;
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << (dp[n]) << "\n";
	}
	return 0;
}