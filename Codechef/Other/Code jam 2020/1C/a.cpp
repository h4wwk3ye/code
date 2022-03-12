//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/May/20 02:37:35 PM
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

	fr (TC, 1, tc + 1) {
		cout << "Case #" << TC << ": ";

		int x, y;
		cin >> x >> y;
		string s;
		cin >> s;
		if (x == 0 and y == 0) {
			pr (0);
			continue;
		}
		int ans = 1e18;
		int t = 0;
		for (auto& i : s) {
			if (i == 'S')
				y--;
			else if (i == 'N')
				y++;
			else if (i == 'E')
				x++;
			else
				x--;
			t++;
			int dist = abs (x) + abs (y);
			if (dist <= t) {
				ans = t;
				break;
			}
		}
		if (ans == 1e18) {
			pr ("IMPOSSIBLE");
		} else {
			pr (ans);
		}
	}

	return 0;
}