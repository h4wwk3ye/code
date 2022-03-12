//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Jan/20 10:17:13 PM
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
	int n;
	cin >> n;
	string s;
	fr (i, 1, n + 1) {
		s += i + '0';
	}

	auto isPrime = [](int n) -> bool {
		if (n <= 1) return false;
		if (n <= 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;

		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 or n % (i + 2) == 0) return false;

		return true;
	};

	int ans = -1;
	do {
		if (s[0] % 2 == 0) {
			bool f = 0;
			fr (i, 2, len (s)) {
				if (s[i] % 2 == 0) {
					f = 1;
					break;
				}
			}
			if (!f) {
				if (isPrime (stoll (s))) {
					pr (s);
					return 0;
				}
			}
		}
	} while (next_permutation (all (s)));

	cout << "Dont Exist for " << n << endl;
	return 0;
}