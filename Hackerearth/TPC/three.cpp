//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Mar/20 10:14:07 PM
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

	ve< int > t;
	int k = 1;
	int j = 1;
	while (k <= 1e18) {
		t.pb (k);
		k *= 3;
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int n, k;
		cin >> n >> k;
		if (k > n) {
			pr ("NO");
			continue;
		}
		while (k--) {
			auto it = lower_bound (all (t), n);
			if (*it != n) --it;
			n -= *it;
			if (n <= 0) break;
		}
		pr (n > 0 ? "NO" : "YES");
	}
	return 0;
}