//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Apr/20 12:02:36 PM
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
		int arr[n][n];
		int trace = 0;
		fr (i, 0, n) {
			fr (j, 0, n) {
				cin >> arr[i][j];
				if (i == j) trace += arr[i][j];
			}
		}
		int rows = 0;
		fr (i, 0, n) {
			unordered_set< int > s;
			fr (j, 0, n) s.insert (arr[i][j]);
			if (len (s) != n) rows++;
		}
		int cols = 0;
		fr (j, 0, n) {
			unordered_set< int > s;
			fr (i, 0, n) s.insert (arr[i][j]);
			if (len (s) != n) cols++;
		}
		pr (trace, rows, cols);
	}
	return 0;
}