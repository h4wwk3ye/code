//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 23/Feb/20 01:14:21 PM
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
int n;
const int N = 1e3 + 5;
int dp[N][N][2];
int arr[N][N];
int solve (int i, int j, int f) {
	if (i == n - 1 and j < n) return arr[i][j];
	if (j == n - 1 and i < n) return arr[i][j];
	if (i >= n or j >= n) return 0;
	int& ans = dp[i][j][f];
	if (ans != -1) return ans;
	ans = 0;

	fr (k, 1, n + 1) {
		if (i + k >= n or j + k >= n) break;

		if (arr[i + k][j + k] > arr[i][j]) {
			ans = max (ans, arr[i][j] + solve (i + k, j + k, 1));
		}
	}
	if (!f) ans = max (ans, solve (i + 1, j + 1, 0));

	return ans;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n) fr (j, 0, n) cin >> arr[i][j];
	int ans = 0;
	reset (dp, -1);
	int X, Y;
	fr (i, 0, n) {
		int curr = solve (0, i, 0);
		if (ans < curr) {
			ans = curr;
			X = i;
			Y = 0;
		}
	}
	fr (i, 1, n) {
		int curr = solve (0, i, 0);
		if (ans < curr) {
			ans = curr;
			X = 0;
			Y = i;
		}
	}
	while (X < n and Y < n)
		pr (X++, Y++);
	return 0;
}