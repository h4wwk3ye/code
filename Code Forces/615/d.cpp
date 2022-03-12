//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Jan/20 09:43:13 PM
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
	int q, x;
	cin >> q >> x;
	unordered_set< int > arr;
	int mn = 0;

	unordered_map< int, int > mp;

	auto func = [&](int mn, int y) {
		int j = ceil ((mn - y) / (x * 1.0));
		int m = y + (x * j);
		return m;
	};

	fr (tc, 0, q) {
		int y;
		cin >> y;

		if (x == 1) {
			pr (tc + 1);
			continue;
		}

		if (arr.find (y) != arr.end ()) {
			int j = y % x;
			if (mp.find (j) == mp.end ()) {
				mp[j] = j;
			} else {
				mp[j] += x;
			}

			arr.insert (mp[j]);
			if (mp[j] == mn) mn++;
			while (arr.find (mn) != arr.end ())
				mn++;
			pr (mn);
			// pr (arr);
			// pr (mp);
			continue;
		}

		if (y == mn) {
			arr.insert (y);
			int j = y % x;
			if (mp.find (j) == mp.end ()) {
				mp[j] = j;
			} else {
				mp[j] += x;
			}
			mn++;
			while (arr.find (mn) != arr.end ())
				mn++;
		} else {
			int j = y % x;
			if (mp.find (j) == mp.end ()) {
				mp[j] = j;
			} else {
				mp[j] += x;
			}
			arr.insert (mp[j]);
			if (mp[j] == mn) mn++;
			while (arr.find (mn) != arr.end ())
				mn++;
		}
		pr (mn);
		// pr (arr);
		// pr (mp);
	}
	return 0;
}