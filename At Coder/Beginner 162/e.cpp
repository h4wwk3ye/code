//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 12/Apr/20 06:25:19 PM
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
	int n, k;
	cin >> n >> k;
	int mod = 1e9 + 7;
	auto power = [&] (int a, int b) {
		int r = 1;
		while (b) {
			if (b & 1) r = (r * a) % mod;
			b >>= 1;
			a = (a * a) % mod;
		}
		return r;
	};

	int ans = 0;
	fr (i, 2, k + 1) {
		ans += power (k / i, n);
		ans %= mod;
	}
	int y = power (k, n + 1);

	pr ((y - ans + mod) % mod, ans);
	return 0;
}