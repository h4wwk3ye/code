//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 03/Apr/20 07:55:26 PM
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
	const int mod = 1e9 + 7;
	auto power = [&] (int a, int b) -> int {
		int r = 1;
		while (b) {
			if (b & 1) r = (r * a) % mod;
			b >>= 1;
			a = (a * a) % mod;
		}
		return r;
	};
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;

		fr (i, 0, n) {
			int l;
			cin >> l;
			if (l == 1) {
				pr (1);
				continue;
			}
			int q = power (52, l);
			int p = power (52 + 2 * k, l / 2);
			if (l & 1) {
				p *= 52;
				p %= mod;
			}
			int ans = p * power (q, mod - 2);
			ans %= mod;
			pr (ans);
		}
	}
	return 0;
}