//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Mar/20 02:11:20 PM
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
	ve< int > arr (n + 1), pref (n + 1, 0);
	fr (i, 1, n + 1) {
		cin >> arr[i];
		pref[i] = arr[i] + pref[i - 1];
	}

	if (n == 1) {
		pr (-1);
		return 0;
	}
	int ans = 0;
	int idx = n - 1;
	dfr (i, n - 1, 0) {
		int x = pref.back () - pref[i];
		int y = pref[i];
		if ((x & y) > ans) {
			ans = (x & y);
			idx = i;
		}
	}
	pr (ans, idx);
	return 0;
}