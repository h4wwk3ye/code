#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Nov/19 11:00:30 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-fordp off

#define int long long
#define ve vector
#define pb push_back
#define endl "\n"
#define ff first
#define ss second
#define pii pair< int, int >
#define len(v) (int)v.size ()
#define all(v) v.begin (), v.end ()
#define reset(a, b) memset (a, b, sizeof (a));
#define fr(i, s, n) for (int i = s; i < n; ++i)
#define dfr(i, s, n) for (int i = s; i > n; --i)

template < typename T > void pr (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	pr (u, args...);
}

// clang-format on

int N, W;

int solve (int c[], int w[], const int& N, const int& W) {
	int dp[W + 1];
	memset (dp, 0, sizeof (dp));
	for (int i = 0; i < N; i++) {
		for (int j = W; j >= w[i]; j--) {
			dp[j] = max (dp[j], dp[j - w[i]] + c[i]);
		}
	}
	return dp[W];
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> N >> W;
	int c[N], w[N];
	fr (i, 0, N) {
		scanf ("%lld", &c[i]);
	}
	fr (i, 0, N) scanf ("%lld", &w[i]);
	// sort (arr, arr + N, greater<> ());
	cout << solve (c, w, N, W);
	return 0;
}