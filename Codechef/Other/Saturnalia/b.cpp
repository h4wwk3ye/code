//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Nov/19 09:43:08 PM
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

const int N = 1e3 + 5;
int arr[N][N];
int dp[N][N];
int n, m;

int solve (int i, int j) {
	if (i == n and j == m) return arr[i][j];
	if (i > n or j > m) return -1e18;
	int& ans = dp[i][j];
	if (ans != 1e18) return ans;
	ans = 0;
	ans = max (solve (i + 1, j), max (solve (i, j + 1), solve (i + 1, j + 1))) + arr[i][j];
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		fr (i, 1, n + 1) {
			fr (j, 1, m + 1) {
				cin >> arr[i][j];
				dp[i][j] = 1e18;
			}
		}
		pr (solve (1, 1));
	}
	return 0;
}