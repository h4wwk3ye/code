//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 06/Jan/20 09:58:16 PM
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
		int n;
		cin >> n;

		bool side = 0;

		int x = n % 12;

		if (x > 3 and x < 10) side = 1;

		if (!side) {
			if (x <= 3 and x != 0) {
				if (x == 1) {
					pr (n + 11);
					pr ("Blue");
				} else if (x == 2) {
					pr (n + 9);
					pr ("Yellow");
				} else {
					pr (n + 7);
					pr ("Red");
				}
			} else {
				if (x == 0) {
					pr (n - 11);
					pr ("Blue");
				} else if (x == 11) {
					pr (n - 9);
					pr ("Yellow");
				} else {
					pr (n - 7);
					pr ("Red");
				}
			}
		} else {
			if (x >= 4 and x <= 6) {
				if (x == 4) {
					pr (n + 5);
					pr ("Red");
				} else if (x == 5) {
					pr (n + 3);
					pr ("Yellow");
				} else {
					pr (n + 1);
					pr ("Blue");
				}
			} else {
				if (x == 9) {
					pr (n - 5);
					pr ("Red");
				} else if (x == 8) {
					pr (n - 3);
					pr ("Yellow");
				} else {
					pr (n - 1);
					pr ("Blue");
				}
			}
		}
	}
	return 0;
}