//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 09/Nov/19 12:29:38 PM
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
		ve< int > d = {1};
		fr (i, 2, sqrt (n) + 1) {
			if (n % i == 0) {
				if (n / i == i) {
					d.pb (i);
				} else {
					d.pb (i);
					d.pb (n / i);
				}
			}
		}
		int s = 0;
		fr (i, 0, len (d)) s += d[i];
		if (s <= n) {
			pr ("NOT SPECIAL");
			continue;
		}
		auto subset_sum = [&] () {
			bool subset[2][n + 1];
			fr (i, 0, len (d) + 1) {
				for (int j = 0; j <= n; j++) {
					if (j == 0)
						subset[i % 2][j] = true;
					else if (i == 0)
						subset[i % 2][j] = false;
					else if (d[i - 1] <= j)
						subset[i % 2][j] = subset[(i + 1) % 2][j - d[i - 1]] or subset[(i + 1) % 2][j];
					else
						subset[i % 2][j] = subset[(i + 1) % 2][j];
				}
			}
			return subset[len (d) % 2][n];
		};
		bool ans = subset_sum ();
		pr (ans ? "NOT SPECIAL" : "SPECIAL");
	}
	return 0;
}