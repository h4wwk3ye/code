//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 07:11:49 PM
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
		int n, s, k;
		cin >> n >> s >> k;
		set< int > se;
		fr (i, 0, k) {
			int x;
			cin >> x;
			se.insert (x);
		}

		int i = s, j = s + 1;
		int ans = 1e18;
		while (i > 0) {
			if (se.find (i) == se.end ()) {
				ans = s - i;
				break;
			}
			i--;
		}

		while (j <= n) {
			if (se.find (j) == se.end ()) {
				ans = min (ans, j - s);
				break;
			}
			j++;
		}
		pr (ans);
	}
	return 0;
}