/*
				C++
				encoding: UTF-8
				Modified: <27/Jul/2019 09:55:57 AM>

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

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on
ll n, m, k;
const int N = 1e5 + 5;
ll arr[N];

ll powermod (ll _a, ll _b, ll _m) {
	ll _r = 1;
	while (_b) {
		if (_b % 2 == 1) _r = (_r * _a) % _m;
		_b /= 2;
		_a = (_a * _a) % _m;
	}
	return _r;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> k;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (j, 1, m + 1) {
		ve< ll > pref (n + 1, 0);
		fr (i, 1, n + 1) {
			pref[i] = powermod (arr[i], j, mod);
			pref[i] += pref[i - 1];
			pref[i] %= mod;
		}
		print (pref);
		cout << pref[n] << " ";
	}
	return 0;
}
