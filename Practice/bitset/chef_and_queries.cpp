//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 12/Feb/20 09:27:09 PM
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

const int N = 5e9 + 5;
bitset< N > bs;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int q, s, a, b;
	cin >> q >> s >> a >> b;
	int ans = 0;
	int x = (1LL << 32);
	while (q--) {
		if (s & 1) {
			if (!bs[s / 2]) ans += s / 2;
			bs.set (s / 2);
		} else {
			if (bs[s / 2]) ans -= s / 2;
			bs.set (s / 2, 0);
		}
		s = (a * s + b) % x;
	}
	pr (ans);
	return 0;
}