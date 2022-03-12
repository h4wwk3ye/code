/*
				C++
				encoding: UTF-8
				Modified: <27/Sep/2019 11:17:00 PM>

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

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}


#define int long long
const int N = 2e6 + 5;
int fact[N];
int mod = 1e9 + 7;
void pre () {
	fact[0] = 1;
	fr (i, 1, N) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	pre ();
	int tc;
	cin >> tc;
	while (tc--) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		int n = abs (x1 - x) + abs (y1 - y);
		int r = min (abs (x1 - x), abs (y1 - y));
		int ans = fact[n] * powermod ((fact[n - r] * fact[r]) % mod, mod - 2, mod);
		ans %= mod;
		pr (ans);
	}
	return 0;
}
