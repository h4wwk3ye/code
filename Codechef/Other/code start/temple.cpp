//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Feb/20 07:57:24 PM
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

const int N = 1e4 + 5;
int dp[N][105];
int h, k, a, b, c;
const int mod = 1e9 + 7;

int solve (int i, int j) {
	if (i == h) {
		return j == k;
	}
	if (j > k or i > h) return 0;
	int& ans = dp[i][j];
	if (ans != -1) return ans;
	ans = solve (i + a, j + 1) + solve (i + b, j + 1) + solve (i + c, j + 1);
	ans %= mod;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> h >> a >> b >> c >> k;
	reset (dp, -1);
	int ans = solve (0, 0);
	ans %= mod;
	pr (ans);
	return 0;
}