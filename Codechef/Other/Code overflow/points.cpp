//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 03:37:23 PM
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
	multiset< int > s;
	int q;
	cin >> q;
	int low = 1e9, high = 0;
	while (q--) {
		int a;
		cin >> a;
		s.insert (a);
		if (len (s) == 1) {
			pr (0);
			continue;
		}
		low = min (low, a);
		high = max (high, a);

		int mid = (low + high) >> 1;
		int ans = 0;
		auto it = s.lower_bound (mid);
		if (it == s.begin ()) {
			int x = *it;
			for (auto& i : s) {
				ans += abs (i - x) * 2;
			}
		} else if (it == s.end ()) {
			it--;
			int x = *it;

			for (auto& i : s) {
				ans += abs (i - x) * 2;
			}
		} else {
			int x = *it;
			for (auto& i : s) {
				ans += abs (i - x) * 2;
			}
			int tmp = 0;
			it--;
			x = *it;
			int ans = 0;
			for (auto& i : s) {
				tmp += abs (i - x) * 2;
			}
			ans = min (ans, tmp);
		}
		pr (ans);
	}
	return 0;
}