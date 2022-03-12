//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
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

const int N = 1e5 + 5;
int arr[N];
ve< ve< ve< int > > > dp;
int n, m, l;
const int mod = 1e9 + 7;

int solve (int i, int j, int k) {
	if (j == n) {
		return k == 0;
	}
	if (i > l) return 0;
	int& ans = dp[i][j][k];
	if (ans != -1) return ans;
	ans = solve (i, j + 1, (k + arr[i]) % m) + solve (i + 1, j + 1, (k + arr[i]) % m) + solve (i + 1, j, k);
	ans %= mod;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> l;
	fr (i, 1, l + 1) cin >> arr[i];
	dp.resize (l + 1);
	fr (i, 1, l + 1) {
		dp[i].resize (n + 1, ve< int > (15, -1));
	}

	int ans = solve (1, 0, 0);
	pr (ans);
	pr (dp);
	return 0;
}