//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/May/20 05:35:57 PM
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
	int n, k;
	cin >> n >> k;
	set< int > s;
	fr (i, 0, k) {
		int d;
		cin >> d;
		fr (j, 0, d) {
			int x;
			cin >> x;
			s.insert (x);
		}
	}
	int ans = 0;
	fr (i, 1, n + 1) {
		if (s.find (i) == s.end ()) ans++;
	}
	pr (ans);
	return 0;
}