//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Jan/20 12:15:38 AM
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

	auto power = [&](int a, int b) -> int {
		int r = 1;
		while (b) {
			if (b & 1) r = r * a;
			b >>= 1;
			a *= a;
		}
		return r;
	};

	auto solve = [&](int n) -> int {
		ve< int > a;
		while (n) {
			a.pb (n % 3);
			n /= 3;
		}

		int ans = 0;
		reverse (all (a));

		fr (i, 0, len (a)) {
			if (a[i] == 1) {
				ans += power (2, len (a) - i - 1);
			} else if (a[i] == 2) {
				ans += power (2, len (a) - i - 1) * 2;
				break;
			}
		}

		return ans - 1;
	};

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int ans = solve (n + 1);
		pr (ans);
	}

	return 0;
}