//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 06/Mar/20 09:09:34 PM
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
		int p, q;
		cin >> p;
		map< int, int > a;
		fr (i, 0, p) {
			int x;
			cin >> x;
			a[x]++;
		}
		cin >> q;
		map< int, int > b;
		fr (i, 0, q) {
			int x;
			cin >> x;
			b[x]++;
		}
		int ans = 0;

		for (auto& i : a) {
			if (b.find (i.ff) != b.end ()) {
				ans++;
			}
		}
		pr (ans);
	}
	return 0;
}