//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Feb/20 07:09:44 PM
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
	int n, q;
	cin >> n >> q;
	ve< int > arr (n);
	fr (i, 0, n) cin >> arr[i];
	sort (all (arr));
	while (q--) {
		int x;
		cin >> x;
		auto it = lower_bound (all (arr), x);
		if (it == arr.begin ()) {
			if (*it == x) {
				pr (x);
			} else {
				pr (-1);
			}
		} else {
			if (it == arr.end () or *it > x) it--;
			pr (*it);
		}
	}
	return 0;
}