/*
				C++
				encoding: UTF-8
				Modified: <21/Jul/2019 12:12:21 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
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
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

set< int > primes;

void SieveOfEratosthenes (int n) {
	bool prime[n + 1];
	reset (prime, true);

	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p]) primes.insert (p);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	SieveOfEratosthenes (1e6);
	auto y = primes.lower_bound (n);
	int x = *y;

	ve< pii > edges;
	fr (i, 1, n) edges.pb ({i, i + 1});
	edges.pb ({1, n});

	fr (i, 1, x - n + 1) edges.pb ({i, (i + n / 2) % n});

	print (len (edges));
	// for (auto [i, j] : edges) print (i, j);
	for (auto i : edges)
		print (i.ff, i.ss);

	return 0;
}
