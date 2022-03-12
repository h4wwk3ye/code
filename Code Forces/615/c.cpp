//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Jan/20 10:04:53 PM
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
	int tc;
	cin >> tc;

	auto solve = [&](int n) {
		set< int > x;

		for (int i = 2; i <= sqrt (n); ++i) {
			if (n % i == 0) {
				x.insert (i);
				x.insert (n / i);
			}
		}

		if (len (x) < 3) {
			pr ("NO");
			return 0;
		}

		ve< int > p;
		for (auto& i : x)
			p.pb (i);

		fr (i, 0, len (p) - 1) {
			int a = p[i];
			int b = p[i + 1];
			int c = n / (a * b);
			if (a != b and b != c and a != c and c > 1 and (a * b * c) == n) {
				pr ("YES");
				pr (a, b, c);
				return 0;
			}
		}
		pr ("NO");
	};

	while (tc--) {
		int n;
		cin >> n;
		solve (n);
	}
	return 0;
}