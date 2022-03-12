//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Mar/20 10:01:02 AM
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
		if (n == 1) {
			pr (-1);
			continue;
		}
		string ans;
		int x = 0;
		fr (i, 0, n - 1) {
			ans += '2';
			x += 2;
			x %= 3;
		}
		if (x % 3 == 0) {
			ans.pop_back ();
			ans += '6';
		}
		ans += '3';
		pr (ans);
	}
	return 0;
}