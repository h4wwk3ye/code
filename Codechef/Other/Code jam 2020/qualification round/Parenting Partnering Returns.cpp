//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Apr/20 12:57:30 PM
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
		int n;
		cin >> n;
		ve< pair< int, pair< char, int > > > arr;
		fr (i, 0, n) {
			int x, y;
			cin >> x >> y;
			arr.pb ({x, {'o', i}});
			arr.pb ({y, {'c', i}});
		}
		sort (all (arr));
		// pr (arr);
		int mx = 0;
		int curr = 0;
		bool c = 0;
		int c_id;
		ve< char > ans (n);
		for (auto& l : arr) {
			int& p = l.ff;
			int& id = l.ss.ss;
			char& st = l.ss.ff;

			if (st == 'o') { //  new addition
				curr++;
				if (c) {
					ans[id] = 'J';
				} else {
					ans[id] = 'C';
					c = 1;
					c_id = id;
				}
			} else {
				curr--;
				if (c) {
					if (id == c_id) {
						c = 0;
					}
				}
			}
			mx = max (mx, curr);
		}
		// pr (mx);
		if (mx > 2) {
			pr ("IMPOSSIBLE");
		} else {
			for (auto& i : ans)
				cout << i;
			cout << '\n';
		}
	}
	return 0;
}