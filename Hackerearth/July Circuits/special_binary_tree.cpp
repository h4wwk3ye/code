/*
				C++
				encoding: UTF-8
				Modified: <24/Jul/2019 03:21:58 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         aint(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

const int N = 1e6 + 5;
int fact[N];

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}


int nCr (int n, int r) {
	ll num = fact[n];
	ll d = (fact[r] * fact[n - r]) % mod;
	d = powermod (d, mod - 2, mod);
	ll ans = num * d;
	ans %= mod;
	return ans;
}

long long binpow (long long a, long long b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	fact[0] = 1;
	fr (i, 1, N) {
		fact[i] = i * fact[i - 1];
		fact[i] %= mod;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int ans = fact[(n + 1) / 2] * fact[n / 2];
		ans %= mod;
		int x = n + 1;
		if (x && (!(x & (x - 1)))) {
			print (ans);
			continue;
		}
		int h = ceil (log2 (n + 1)) - 1;
		x = binpow (2, h - 1) - 1;
		int e = x, o = x + 1;
		int odd = (n + 1) / 2, even = n / 2;
		even -= e, odd -= o;

		int l = x + 1;
		int curr = nCr (l, even) * nCr (l, odd);
		curr %= mod;

		e = x + 1, o = x;
		odd = (n + 1) / 2, even = n / 2;
		even -= e, odd -= o;
		curr += nCr (l, even) * nCr (l, odd);
		curr %= mod;
		ans = ans * curr;
		ans %= mod;
		print (ans);
	}
	return 0;
}
