//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 13/Mar/20 09:40:13 AM
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
	ve< int > a (n), b (n);
	for (auto& i : a)
		cin >> i;
	for (auto& i : b)
		cin >> i;
	ve< int > c (n), d (n);
	fr (i, 0, n) {
		c[i] = a[i] - b[i];
		d[i] = b[i] - a[i];
	}
	sort (all (c));
	sort (all (d));

	int ans = 0;
	fr (i, 0, n) {
		int x = c[i];
		int j = lower_bound (all (d), x) - d.begin ();
		ans += j;
		if (x > 0) ans--;
	}
	ans /= 2;
	pr (ans);
	return 0;
}