//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 02:58:00 PM
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

const int N = 1e6 + 5;
int fact[N];

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int m, k;
	cin >> m >> k;
	int arr[k];
	int t = 0;
	fr (i, 0, k) {
		int x;
		cin >> x;
		t += x;
		arr[i] = x;
	}
	if (t > m) {
		pr (0);
		return 0;
	}

	m -= t;

	const int mod = 1e9 + 7;
	auto power = [&](int a, int b) -> int {
		int r = 1;
		while (b) {
			if (b & 1) r = (r * a) % mod;
			a = (a * a) % mod;
			b >>= 1;
		}
		return r;
	};


	fact[0] = 1;
	fr (i, 1, N) fact[i] = (fact[i - 1] * i) % mod;

	int n = m + k - 1;
	int r = k - 1;

	int ans = (fact[n] * power (fact[r], mod - 2)) % mod;
	ans = (ans * (power (fact[n - r], mod - 2)) % mod) % mod;
	pr (ans);
	return 0;
}