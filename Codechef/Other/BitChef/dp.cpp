//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 11/Nov/19 12:09:30 AM
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
const int N = 3e6 + 5;
int arr[20];
int dp[20][N];

int solve (int i, int j) {
	if (i == n) {
		int c = 1;
		fr (p, 0, n) {
			int x = (j >> p) & 1;
			if (x) c *= arr[p];
		}
		return c >= k;
	}
	if (dp[i][j]) return dp[i][j];
	dp[i][j] = solve (i + 1, j) + solve (i + 1, j | (1LL << i));
	return dp[i][j];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		fr (i, 0, pow (2, n + 1) + 5) fr (j, 0, 20) dp[j][i] = 0;
		fr (i, 0, n) cin >> arr[i];
		int ans = solve (0, 0);
		pr (ans);
	}
	return 0;
}