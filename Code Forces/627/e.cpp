//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 13/Mar/20 09:52:26 AM
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

const int N = 2e3 + 5;
int arr[N];
int n, h, l, r;
int dp[N][N]; // index & time

int solve (int i, int j) {
	if (i == n + 1) return 0;
	int& ans = dp[i][j];
	if (ans != -1) return ans;

	ans =
	max (solve (i + 1, (j + arr[i] - 1) % h) +
		 ((((j + arr[i] - 1) % h) >= l and ((j + arr[i] - 1) % h) <= r) ? 1 : 0),
		 solve (i + 1, (j + arr[i]) % h) + ((((j + arr[i]) % h) >= l and ((j + arr[i]) % h) <= r) ? 1 : 0));
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> h >> l >> r;
	fr (i, 1, n + 1) cin >> arr[i];

	reset (dp, -1);

	int ans = solve (1, 0);
	pr (ans);
	return 0;
}