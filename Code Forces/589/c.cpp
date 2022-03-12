/*
				C++
				encoding: UTF-8
				Modified: <29/Sep/2019 08:35:29 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on
#define int long long
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
int X, N;
set< int > factors;

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}


void primeFactors (int n) {
	while (n % 2 == 0) {
		factors.insert (2);
		// cout << 2 << " ";
		n = n / 2;
	}
	for (int i = 3; i <= sqrt (n) + 1000; i = i + 2) {
		while (n % i == 0) {
			factors.insert (i);
			// cout << i << " ";
			n = n / i;
		}
	}
	if (n > 2) {
		factors.insert (n);
		// cout << n << " ";
	}
}

// int g (int x, int p) {
// 	int m = 1;
// 	while ((x % powermod (p, m, mod)) == 0)
// 		m++;
//
// 	return m - 1;
// }
//
// int f (int x, int y) {
// 	int curr = 1;
// 	for (int i : factors) {
// 		int h = g (y, i);
// 		// pr (y, i, h);
// 		curr *= powermod (i, h, mod);
// 		curr %= mod;
// 		// curr *= g (k, i);
// 	}
// 	return curr % mod;
// }

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> X >> N;
	primeFactors (X);
	int ans = 1;
	for (auto i : factors) {
		int f = N / i;
		f %= mod;
		int cnt = 0;
		int p = 1;
		int j = i;
		while (j < N) {
			cnt++;
			ans *= powermod (j, p, mod);
			ans %= mod;
			p++;
			j *= i;
		}
		pr (i, f, cnt);
		f -= cnt;
		f %= mod;
		if (f > 0) {
			ans *= powermod (i, f, mod);
		}
		ans %= mod;
	}
	pr (ans);

	// auto it = factors.end ();

	/*it--;
	int chk = *it;

	int k = 1;
	int ans = 1;
	while (k <= chk and k <= N) {
		ans *= f (X, k);
		k++;
		ans %= mod;
	}

	pr (factors);*/
	// pr (ans % mod);
	// pr (593574252 / ans);
	// pr (626794 * ans);
	//
	// int f_ = floor (N * 1.0 / k);
	// f_ %= mod;
	// pr (f_);
	// ans = powermod (ans, f_, mod);
	return 0;
}
