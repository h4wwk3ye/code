//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Jan/20 10:37:22 PM
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
		int k;
		cin >> k;
		int rooms[k + 1];
		fr (i, 1, k + 1) cin >> rooms[i];
		sort (rooms + 1, rooms + k + 1);
		int n;
		cin >> n;
		int a[n + 1], d[n + 1];
		fr (i, 1, n + 1) cin >> a[i];
		fr (i, 1, n + 1) cin >> d[i];
		ve< int > cnt (6, 0);
		int ans = 0;
		fr (day, 1, 6) {
			int cnt = 0;
			fr (i, 1, n + 1) {
				if (a[i] <= day and d[i] > day) cnt++;
			}
			fr (i, 1, cnt + 1) ans += rooms[i];
		}
		pr (ans);
	}
	return 0;
}