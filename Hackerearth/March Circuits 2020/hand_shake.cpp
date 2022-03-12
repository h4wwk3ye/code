//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/20 10:40:58 PM
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
	int n;
	cin >> n;
	int arr[10][10];
	fr (i, 0, 10) fr (j, 0, 10) cin >> arr[i][j];
	int ans = (n * (n - 1)) / 2;

	set< pii > s;
	fr (i, 0, 10) {
		fr (j, 1, 10) {
			int x = min (arr[i][0], arr[i][j]);
			int y = max (arr[i][0], arr[i][j]);
			if (s.find ({x, y}) == s.end ()) {
				ans--;
			}
			s.insert ({x, y});
		}
	}
	pr (ans);
	return 0;
}