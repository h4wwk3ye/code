//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Mar/20 04:58:28 PM
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
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m;
	cin >> n >> m;
	vector< vector< int > > a (n, vector< int > (m, 0));
	fr (i, 0, n) fr (j, 0, m) cin >> a[i][j];
	vector< vector< int > > b (n, vector< int > (m, 0));

	fr (i, 0, n) {
		fr (j, 0, m) {
			if (a[i][j]) {
				fr (k, 0, n) b[k][j] = 1;
				fr (k, 0, m) b[i][k] = 1;
			}
		}
	}

	vector< vector< int > > c (n, vector< int > (m, 1));

	fr (i, 0, n) {
		fr (j, 0, m) {
			fr (k, 0, m) {
				c[i][j] &= b[i][k];
			}
			fr (k, 0, n) {
				c[i][j] &= b[k][j];
			}
		}
	}
	bool ans = 1;
	fr (i, 0, n) fr (j, 0, m) if (a[i][j] != c[i][j]) ans = 0;
	pr (ans);
	return 0;
}