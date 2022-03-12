//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 26/Mar/20 09:08:09 PM
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
		int n, k;
		cin >> n >> k;
		string ans (n, 'a');

		int s = 1;
		int i = 1;
		int p = 1;

		while (s < k) {
			i++;
			p = s;
			s += i;
		}
		ans[n - i - 1] = 'b';
		if (s == k) {
			ans[n - i] = 'b';
			pr (ans);
			continue;
		}

		int x = 0;
		p++;
		while (p != k) {
			x++;
			p++;
		}
		ans[n - 1 - x] = 'b';
		pr (ans);
	}
	return 0;
}