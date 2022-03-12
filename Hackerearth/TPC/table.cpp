//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Mar/20 10:01:34 PM
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
	int n, p;
	cin >> n >> p;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	ve< int > tables;
	int m = 1;

	auto power = [](int a, int b) {
		int r = 1;
		while (b) {
			if (b & 1) r = r * a;
			a = a * a;
			b >>= 1;
		}
		return r;
	};

	while (true) {
		int x = power (p, m);
		if (x > 1e8) break;
		tables.pb (x);
		m++;
	}
	int ans = 0;
	for (auto& i : arr) {
		auto it = lower_bound (all (tables), i);
		ans += *it;
	}
	pr (ans);
	return 0;
}