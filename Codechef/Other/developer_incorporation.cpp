//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 29/Mar/20 03:24:56 PM
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

const int N = 1e5 + 5, mod = 1e9 + 7;
int dp[N], fact[N];

int power (int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = (r * a) % mod;
		b >>= 1;
		a = (a * a) % mod;
	}
	return r;
}

int ncr (int n, int r) {
	int num = fact[n];
	int d = fact[n - r] * fact[r];
	d %= mod;
	int ans = num * power (d, mod - 2);
	return ans % mod;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	fact[0] = 1;
	dp[0] = 1, dp[1] = 0, dp[2] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = i * fact[i - 1];
		fact[i] %= mod;
		if (i < 2) continue;
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
		dp[i] %= mod;
	}
	int n = 4;
	int b = 2;
	int ans = 1; // same premutation
	for (int i = b; i > 1; --i) {
		ans += ncr (n, n - i) * dp[i]; // selecting n-i objects to fix at original positon and arranging remaining
		ans %= mod;
	}
	pr (ans);
	return 0;
}