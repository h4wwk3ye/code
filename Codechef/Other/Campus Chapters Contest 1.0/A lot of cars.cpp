//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/Apr/20 07:09:30 PM
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
		int n, m;
		cin >> n >> m;
		map< int, ve< int > > arr;
		int mn = -1, mx = -1;
		fr (i, 0, n) {
			fr (j, 0, m) {
				char x;
				cin >> x;
				if (x == 'P') {
					arr[i].pb (j);
					if (mn == -1) {
						mn = i;
					}
					mx = i;
				}
			}
		}

		if (mn == -1) { // no car
			pr (0);
			continue;
		}

		bool right = 1;

		auto it = arr.begin ();
		if ((*it).ff & 1) {
			right = 0;
		}

		auto manhattan = [] (int x1, int y1, int x2, int y2) -> int {
			return abs (x1 - x2) + abs (y1 - y2);
		};

		auto solve = [&] () -> int {
			pii p = {-1, -1};
			int curr = 0;
			for (auto& i : arr) {
				ve< int > t = i.ss;
				if (i.ff & 1) reverse (all (t));

				if (p.ff == -1 and p.ss == -1) {
					p = {i.ff, t[0]};
				}
				for (auto& j : t) {
					curr += manhattan (p.ff, p.ss, i.ff, j);
					p = {i.ff, j};
				}
			}
			return curr;
		};
		int ans;
		if (right)
			ans = solve (); // top left
		else
			ans = solve (); // top right
		pr (ans);
	}
	return 0;
}