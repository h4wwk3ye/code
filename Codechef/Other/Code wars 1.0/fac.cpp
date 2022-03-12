//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jan/20 08:28:02 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		set< int > factors;

		auto fun = [&](int n) -> void {
			fr (i, 1, sqrt (n) + 1) {
				if (n % i == 0) {
					if (n / i == i) {
						factors.insert (i);
					} else {
						factors.insert (n / i);
						factors.insert (i);
					}
				}
			}
		};

		fun (n);
		int ans = 1;
		const int mod = 1e9 + 7;
		for (auto& i : factors) {
			ans *= (i + 1);
			ans %= mod;
		}
		ans = (ans - 1 + mod) % mod;
		pr (ans);
	}
	return 0;
}