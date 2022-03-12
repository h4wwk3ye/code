//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Mar/20 10:38:52 AM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int ans = 0;
		if (x - 1 >= 0) {
			ans = max (ans, x * b);
		}
		if (y - 1 >= 0) {
			ans = max (ans, a * y);
		}
		if (x + 1 < a) {
			ans = max (ans, (a * b) - ((x + 1) * b));
		}
		if (y + 1 < b) {
			ans = max (ans, (a * b) - ((y + 1) * a));
		}
		pr (ans);
	}
	return 0;
}