/*
				C++
				encoding: UTF-8
				Last Modified: 24/Sep/20 09:55:34 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

const int N = 3e5 + 5, mod = 998244353;
array< int, N > fact;
int n, k;

int power (int a, int b) {
	int r = 1;
	while (b) {
		if (b & 1) r = r * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return r;
}

int nCr (int n, int r) {
	int num = fact[n];
	int den = fact[r] * fact[n - r] % mod;
	return num * power (den, mod - 2) % mod;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> k;
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = fact[i - 1] * i % mod;
	}

	set< int > s;
	vector< tuple< int, int, int > > arr;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		arr.push_back ({l, 0, i});
		arr.push_back ({r, 1, i});
	}
	sort (arr.begin (), arr.end ());
	n = (int)arr.size ();
	int ans{0};
	for (auto& [p, t, i] : arr) {
		bool flag = false;
		if (t == 0) {
			// new index
			s.insert (i + 1);
			flag = true;
		} else {
			s.erase (i + 1);
		}
		int l = (int)s.size ();
		if (l >= k) {
			if (flag) {
				// print (l, k, s, nCr (l, k));
				ans += nCr (l - 1, k - 1);
				ans %= mod;
			}
		}
	}
	print (ans);
	return 0;
}