//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/May/20 03:09:16 PM
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
	freopen ("in.txt", "r", stdin);

	int tc;
	cin >> tc;

	fr (TC, 1, tc + 1) {
		cout << "Case #" << TC << ": ";
		int u;
		cin >> u;
		map< int, string > mp;
		vector< pair< int, string > > queries;
		fr (i, 0, 1e4) {
			int m;
			string s;
			cin >> m >> s;
			if (m == -1) continue;
			queries.pb ({m, s});
		}
		sort (all (queries));
		set< string > se;
		int p = -1;
		for (auto& i : queries) { // wil come in order 1-2-3
			int& m = i.ff;
			string& s = i.ss;
			if (m == 0) {
				mp[m] = s;
				se.insert (s);
			} else {
				if (m == 10) {
					if (len (s) == 2) {
						mp[0] = s[1];
						break;
					}
					continue;
				}

				if (mp.find (m) == mp.end ()) {
					if (se.find (s) == se.end ()) {
						mp[m] = s;
						se.insert (s);
					}
				}
			}
		}
		// pr (mp);
		fr (i, 0, 10) cout << mp[i];
		cout << '\n';
	}
	return 0;
}