//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Mar/20 09:35:44 PM
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

int func (int x, int a, int b, int x1, int x2) {
	if ((a == 0) and (b == 0)) return 1;
	if (a == b) {
		if ((x1 == x) and (x2 == x)) return 0;
		return 1;
	} else if (a > b) {
		if ((x - (a - b)) >= x1) return 1;
		return 0;
	} else {
		if ((x + b - a) <= x2) return 1;
		return 0;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	if (func (x, a, b, x1, x2) and func (y, c, d, y1, y2)) {
		pr ("YES");

	} else {
		pr ("NO");
	}
	return 0;
}