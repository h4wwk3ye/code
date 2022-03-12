//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/Nov/19 11:13:29 PM
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
	int n, k, x;
	cin >> n >> k >> x;
	string s;
	cin >> s;
	int o = 0, z = 0;
	for (auto& i : s) {
		i == '1' ? o++ : z++;
	}
	if (x == 0) {
		pr (o);
	} else {
		int ans = o;
		dfr (i, min (k, z), -1) {
			int j = k - i;
			if (j > o) continue;
			int z_ = z - i + j;
			if (z_ % k == 0) ans = n;
			pr (n - z_, i, j);
			ans = max (ans, n - z_);
		}
		if (ans != n) ans = n - 1;
		pr (ans);
	}
	return 0;
}