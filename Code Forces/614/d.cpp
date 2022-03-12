//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 11:03:52 PM
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
	int x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;

	ve< pii > points;
	points.pb ({x0, y0});

	int xs, ys, t;
	cin >> xs >> ys >> t;

	int x = x0, y = y0;

	auto manhattan = [](int x1, int y1, int x2, int y2) { return abs (x1 - x2) + abs (y1 - y2); };

	while (1) {
		x = ax * x + bx;
		y = ay * y + by;
		if (x < 0 or y < 0) break;
		points.pb ({x, y});
	}

	int ans = 0, curr = 0;

	fr (i, 0, len (points)) {
		int T = t;
		int XS = xs, YS = ys;
		curr = 0;
		bool f = 1;
		fr (j, i, len (points)) {
			x = points[j].ff, y = points[j].ss;
			int dist = manhattan (XS, YS, x, y);
			T -= dist;
			XS = x, YS = y;
			curr++;
			if (T < 0) {
				ans = max (ans, curr - 1);
				f = 0;
				break;
			}
		}
		if (f) ans = max (ans, curr);
	}

	dfr (i, len (points) - 1, -1) {
		int T = t;
		int XS = xs, YS = ys;
		curr = 0;
		bool f = 1;
		fr (j, i, len (points)) {
			x = points[j].ff, y = points[j].ss;
			int dist = manhattan (XS, YS, x, y);
			T -= dist;
			curr++;
			XS = x, YS = y;
			if (T < 0) {
				ans = max (ans, curr - 1);
				f = 0;
				break;
			}
		}
		if (f) ans = max (ans, curr);
	}

	pr (ans);
	return 0;
}