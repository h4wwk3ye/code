//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 11/Mar/20 10:36:02 PM
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

int n, m;
ve< ve< ve< int > > > dp;
ve< ve< int > > arr;
const int mod = 1e9 + 7;

int solve (int i, int j, int cnt) {
	if (i > n or j <= 0 or j > m) return 0;
	if (i == n) return (cnt & 1);
	int& ans = dp[i][j][cnt];
	if (ans != -1) return ans;
	ans = (solve (i + 2, j - 1, (cnt + 1) % 2) + solve (i + 2, j + 1, (cnt + 1) % 2)) % mod +
		  (solve (i + 1, j - 2, (cnt + 1) % 2) + solve (i + 1, j + 2, (cnt + 1) % 2)) % mod;
	ans %= mod;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	arr.resize (n + 1, ve< int > (m + 1));
	dp.resize (n + 1, ve< ve< int > > (m + 1, ve< int > (2, -1)));
	int ans = 0;
	for (int j = 2; j <= m; j += 2) {
		ans += solve (1, j, 0);
		ans %= mod;
	}
	pr (ans);
	return 0;
}