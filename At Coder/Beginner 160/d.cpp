#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Mar/20 06:16:57 PM
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
	int n, x, y;
	cin >> n >> x >> y;
	map< int, int > mp;
	fr (i, 1, x + 1) {
		fr (j, i + 1, x + 1) {
			mp[j - i]++;
		}
		fr (j, x + 1, n + 1) {
			int ans = min (j - i, x - i + 1 + abs (y - j));
			mp[ans]++;
		}
	}

	fr (i, x + 1, y + 1) {
		fr (j, i + 1, n + 1) {
			int ans = min (j - i, i - x + 1 + abs (j - y));
			mp[ans]++;
		}
	}

	fr (i, y + 1, n + 1) {
		fr (j, i + 1, n + 1) {
			mp[j - i]++;
		}
	}

	fr (i, 1, n) pr (mp[i]);

	return 0;
}