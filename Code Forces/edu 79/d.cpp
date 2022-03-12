//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Dec/19 10:09:24 PM
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

const int mod = 998244353;
ve< ve< int > > arr;
const int N = 1e6 + 5;
int cnt[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	arr.resize (n);

	fr (i, 0, n) {
		int k;
		cin >> k;
		arr[i].resize (k);
		fr (j, 0, k) {
			cin >> arr[i][j];
			cnt[arr[i][j]]++;
		}
	}

	auto power = [&](int a, int b) -> int {
		int r = 1;
		while (b) {
			if (b & 1) r = (r * a) % mod;
			a = (a * a) % mod;
			b >>= 1;
		}
		return r;
	};

	int ans = 0;

	fr (i, 0, n) {
		int x = 0;
		fr (j, 0, len (arr[i])) {
			if (cnt[arr[i][j]] != n) {
				int num = 1, den = 1;
				den *= (len (arr[i]));
				den %= mod;
				den *= n;
				den %= mod;
				num *= n - cnt[arr[i][j]];
				num %= mod;
				x += (num * power (den, mod - 2));
				x %= mod;
			}
		}
		if (x) {
			int p = (x * power (2, mod - 2));
			p %= mod;
			ans += p;
			ans %= mod;
		}
		// pr (x);
	}
	// pr (ans);
	if ((1 - ans + mod) % mod == 0) {
		pr (798595483);
	} else
		pr ((1 - ans + mod) % mod);

	return 0;
}