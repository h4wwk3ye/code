//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/20 11:35:09 PM
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
	int x, y, p, q;
	cin >> x >> y >> p >> q;
	ve< int > ans;
	int g1 = __gcd (x, p);

	int b3 = x / g1;
	int b33 = b3;
	int b1 = p / g1;
	int b11 = b1;
	while (true) {
		// rhs is multiplied by b3 and lhs by b1
		int c = b3 * q; // rhs h
		int b2 = c / y;
		if (b2 * y != c) {
			b1 += b11;
			b3 += b33;
		} else {
			// pr (b1 * x, b3 * p, b2 * y, b3 * q);
			ans = {b1, b2, b3};
			break;
		}
	}

	int g = __gcd (ans[0], __gcd (ans[1], ans[2]));

	pr (ans[0] / g, ans[1] / g, ans[2] / g);

	return 0;
}
