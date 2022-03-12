//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Apr/20 08:49:51 PM
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
		ve< int > a (n), b (n), pos (3, 1e9);

		fr (i, 0, n) {
			cin >> a[i];
			if (a[i] == -1) {
				if (pos[0] == 1e9) pos[0] = i;
			} else if (a[i] == 0) {
				if (pos[1] == 1e9) pos[1] = i;
			} else {
				if (pos[2] == 1e9) pos[2] = i;
			}
		}
		bool ans = 1;
		fr (i, 0, n) cin >> b[i];
		dfr (i, n - 1, -1) {
			if (a[i] == b[i]) continue;
			if (a[i] > b[i]) { // needs -1
				if (pos[0] >= i) ans = 0;
			} else {
				if (pos[2] >= i) ans = 0;
			}
		}
		pr (ans ? "YES" : "NO");
	}
	return 0;
}