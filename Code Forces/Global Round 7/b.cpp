//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Mar/20 10:01:00 AM
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
	int n;
	cin >> n;
	int b[n], a[n];
	fr (i, 0, n) cin >> b[i];
	a[0] = b[0];
	int mx = a[0];
	fr (i, 1, n) {
		a[i] = b[i] + max (mx, a[i - 1]);
		mx = max (mx, a[i] - b[i]);
	}
	fr (i, 0, n) cout << a[i] << " ";
	cout << '\n';
	return 0;
}