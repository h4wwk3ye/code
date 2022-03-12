//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Feb/20 08:22:26 PM
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
		string s;
		cin >> s;
		map< pii, int > mp;
		int x = 0, y = 0;
		mp[{x, y}] = 0;
		int ans = 1e18;
		int X, Y;
		fr (i, 0, n) {
			if (s[i] == 'L') {
				x--;
			} else if (s[i] == 'R') {
				x++;
			} else if (s[i] == 'U') {
				y++;
			} else {
				y--;
			}
			if (mp.find ({x, y}) != mp.end ()) {
				if (ans > i - mp[{x, y}]) {
					ans = i - mp[{x, y}];
					X = mp[{x, y}] + 1;
					Y = i + 1;
				}
				ans = min (ans, i - mp[{x, y}]);
			}
			mp[{x, y}] = i + 1;
		}
		if (ans != 1e18) {
			pr (X, Y);
		} else {
			pr (-1);
		}
	}
	return 0;
}