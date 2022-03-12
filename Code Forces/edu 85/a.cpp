//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 10/Apr/20 08:09:37 PM
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
		pii arr[n];
		fr (i, 0, n) cin >> arr[i].ff >> arr[i].ss;
		int x = 0, y = 0;
		bool ans = 1;
		fr (i, 0, n) {
			if (arr[i].ff < x or arr[i].ss < y) ans = 0;
			if (arr[i].ff - x < arr[i].ss - y) ans = 0;
			x = arr[i].ff;
			y = arr[i].ss;
		}
		pr (ans ? "YES" : "NO");
	}
	return 0;
}