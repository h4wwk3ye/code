//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Mar/20 05:26:43 PM
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

int r, p;
const int N = 1e3 + 5;
int dp[N][N][2];
const int mod = 1e9 + 7;

int solve (int i, int cnt, int flag, string x) { // i chance, cnt of s, !flag only arya has moved
	if (i == r) {
		pr (x);
		return 1;
	}
	if (flag) {
		if ((i - cnt) < cnt * p) return 0;
	}

	int& ans = dp[i][cnt][flag];
	if (ans != -1) return ans;

	ans = solve (i + 1, cnt, flag, x + 'a') + solve (i + 1, cnt + 1, 1, x + 'b');
	ans %= mod;
	return ans;
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> r >> p;
		memset (dp, -1, sizeof dp);
		int ans = solve (0, 0, 0, "");
		pr (ans);
	}
	return 0;
}