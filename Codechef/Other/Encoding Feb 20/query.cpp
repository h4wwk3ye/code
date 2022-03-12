//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 23/Feb/20 12:40:09 PM
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
	int n, q, h;
	cin >> n >> q >> h;
	int arr[h];
	ve< int > left (n + 1, 1e9), right (n + 2, 1e9);
	left[0] = 0;
	right[n + 1] = 0;
	int mn = 1e9, mx = 0;
	fr (i, 0, h) {
		cin >> arr[i];
		mn = min (mn, arr[i]);
		mx = max (mx, arr[i]);
		left[arr[i]] = 0;
		right[arr[i]] = 0;
	}

	fr (i, mn, n + 1) {
		if (left[i] == 0) continue;
		left[i] = 1 + left[i - 1];
	}

	dfr (i, mx, 0) {
		if (right[i] == 0) continue;
		right[i] = 1 + right[i + 1];
	}

	while (q--) {
		int k;
		cin >> k;
		pr (min (left[k], right[k]));
	}

	return 0;
}