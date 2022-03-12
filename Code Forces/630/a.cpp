//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Mar/20 07:16:43 PM
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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool ans = 1;
		if (a or b) {
			if (x1 == x2) {
				ans = 0;
			}
		}
		if (c or d) {
			if (y1 == y2) {
				ans = 0;
			}
		}
		if (!ans) {
			pr ("NO");
			continue;
		}

		int p = min (a, b);
		a -= p;
		b -= p;

		if (a) {
			if (x - x1 < a) {
				ans = 0;
			}
		} else if (b) {
			if (x2 - x < b) {
				ans = 0;
			}
		}

		p = min (c, d);
		c -= p;
		d -= p;

		if (c) {
			if (y - y1 < c) {
				ans = 0;
			}
		} else if (d) {
			if (y2 - y < d) {
				ans = 0;
			}
		}
		pr (ans ? "YES" : "NO");
	}
	return 0;
}