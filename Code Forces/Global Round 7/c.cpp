//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 20/Mar/20 10:01:03 AM
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
	int n, k;
	cin >> n >> k;
	const int mod = 998244353;
	pii arr[n + 1];

	fr (i, 1, n + 1) {
		int x;
		cin >> x;
		arr[i] = {x, i};
	}
	sort (arr + 1, arr + n + 1, greater<> ());
	ve< int > x;
	int t = 0;
	fr (i, 1, k + 1) {
		t += arr[i].ff;
		x.pb (arr[i].ss);
	}
	sort (all (x));
	int ans = 1;

	fr (i, 0, k - 1) {
		ans *= (x[i + 1] - x[i]);
		ans %= mod;
	}
	pr (t, ans);
	return 0;
}