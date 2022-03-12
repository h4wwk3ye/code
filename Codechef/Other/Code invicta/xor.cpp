//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 25/Mar/20 10:09:21 PM
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
	int n;
	cin >> n;
	int q;
	cin >> q;
	set< int > s;
	s.insert (0);
	s.insert (n + 1);
	auto find_xor = [](int n) {
		switch (n & 3) {
		case 0:
			return n;
		case 1:
			return 1ll;
		case 2:
			return n + 1;
		case 3:
			return 0ll;
		}
	};
	set< int > already;
	already.insert (0);
	already.insert (n + 1);
	while (q--) {
		int t, x;
		cin >> t >> x;
		if (t == 1) {
			if (already.find (x) != already.end ()) continue;
			already.insert (x);
			int p = x - 1;
			while (p and s.find (p) != s.end ()) {
				s.erase (p);
				p--;
			}

			if (s.find (x + 1) != s.end ()) continue;
			s.insert (x);
		} else {
			if (already.find (x) == already.end ()) {
				int l = x;
				int r = *already.lower_bound (l);
				int ans = find_xor (r - 1) ^ find_xor (l - 1);
				pr (x, l, r, s, already, '1');
				// pr (ans);
				continue;
			}
			auto it = s.lower_bound (x);

			while (*it <= n and already.find (*it + 1) != already.end ()) {
				it++;
			}
			int l = *it;
			if (l == n + 1) {
				pr (0);
				continue;
			}
			int r = *already.upper_bound (l);
			int ans = find_xor (r - 1) ^ find_xor (l);
			// pr (x, l, r, s, already, '2');
			pr (ans);
		}
	}
	return 0;
}