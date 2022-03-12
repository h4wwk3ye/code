//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Dec/19 06:08:37 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 2e18;
	if ((a & 1) == (b & 1)) {
		ans = abs (a - b) / 2;
	} else {
		int y = min (a, b);
		ans = y + abs (abs (y - max (a, b)) - 1) / 2;

		y = max (a, b);

		ans = min (ans, (n - y + 1) + (abs (abs ((n - y) + min (a, b)) - n)) / 2);
	}
	int p = n - a;
	int q = n - b;

	int x = min (max (p, q), max (a - 1, b - 1));

	ans = min (ans, x);
	pr (ans);

	return 0;
}