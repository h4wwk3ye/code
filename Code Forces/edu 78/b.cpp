//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Dec/19 09:50:26 PM
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

int solve (int i, int j, int k) {
	if (i == j) return 0;
	if (k == 20) return 1e9;
	return 1 + min (solve (i + k, j, k + 1), solve (i, j + k, k + 1));
}


signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap (a, b);
		b -= a;
		a -= a;
		int n = 0;
		bool f = 0;
		while (true) {
			int x = (n * (n + 1) / 2);
			if (x == (b - a)) {
				f = 1;
				break;
			} else if (x > (b - a)) {
				break;
			}
			n++;
		}
		pr (solve (a, b, 1));
		if (f) {
			pr (n);
		} else {
			int y = (n * (n + 1) / 2);
			int x = (n * (n - 1) / 2);
			if (y - b > b - x) {
				pr (n - 1);
			} else if (y - b < b - x) {
				pr (n + 1);
			} else {
				pr (n);
			}
		}
	}
	return 0;
}