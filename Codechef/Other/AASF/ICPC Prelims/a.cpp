//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/20 05:03:34 PM
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
int a[16], b[16], c[16], d[16];
int dp[16][1024];

int Rec (int pos, int left) {
	if (pos > m) return 0;
	if (!left) return 0;

	int& res = dp[pos][left];
	if (res != -1) return res;

	res = 0;
	for (int C = 0, B = 0, D = 0; C <= left && B <= a[pos]; C += c[pos], B += b[pos], D += d[pos])
		res = max (res, Rec (pos + 1, left - C) + D);

	return res;
}
signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> c[0] >> d[0];
	fr (i, 1, m + 1) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	reset (dp, -1);
	int ans = Rec (0, n);
	pr (ans);

	return 0;
}