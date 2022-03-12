//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Apr/20 11:55:56 AM
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
		int x;
		cin >> x;
		int n;
		int a[n];
		fr (i, 0, n) cin >> a[i];
		int m;
		int b[m];
		fr (i, 0, m) cin >> b[i];

		int ans = 0;
		int curr = 0;

		fr (i, 0, m) {
			if (i < n) {
				if (b[i] - a[i] <= x) curr++;
			} else {
				if (curr == n) ans++;
				if (b[i - m] - a[(i - m) % n] <= x) curr--;
				if (b[i] - a[()]) }
		}
	}
	return 0;
}