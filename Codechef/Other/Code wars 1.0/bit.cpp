//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jan/20 10:11:01 PM
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
	auto power = [&](int a, int b) {
		int r = 1;
		while (b) {
			if (b & 1) r = r * a;
			b >>= 1;
			a *= a;
		}
		return r;
	};

	int tc;
	cin >> tc;

	while (tc--) {
		int n;
		cin >> n;
		n++;
		int ans = 0;

		fr (i, 1, 32) {
			int k = 0;
			int x = power (2, i);
			k = (n / x) * (x / 2);
			int y = n % x;
			if (y >= x / 2) {
				k += (y - x / 2);
			}
			k %= mod;
			k = (n - k + mod - 1) % mod;

			ans += power (2, i) % mod *
				   ((((n - 1) * (n - 2)) / 2) % mod - ((k * (k - 1)) / 2) % mod + mod) % mod;
			ans %= mod;
		}
		ans *= 2;
		n--;
		ans = (ans - ((n * (n + 1)) / 2) + mod) % mod;
		pr (ans);
	}
	return 0;
}