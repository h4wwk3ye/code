//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Mar/20 07:30:20 PM
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

const int MAXN = 1e3 + 5;

int spf[MAXN];

void sieve () {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)

		// marking smallest prime factor for every
		// number to be itself.
		spf[i] = i;

	// separately marking spf for every even
	// number as 2
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		// checking if i is prime
		if (spf[i] == i) {
			// marking SPF for all numbers divisible by i
			for (int j = i * i; j < MAXN; j += i)

				// marking spf[j] if it is not
				// previously marked
				if (spf[j] == j) spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector< int > getFactorization (int x) {
	vector< int > ret;
	while (x != 1) {
		ret.push_back (spf[x]);
		x = x / spf[x];
	}
	return ret;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	sieve ();
	int tc;
	cin >> tc;
	while (tc--) {
		map< int, int > mp;
		int n;
		cin >> n;
		int arr[n];
		int c = 0;
		ve< int > ans (n);
		fr (i, 0, n) {
			cin >> arr[i];
			vector< int > x = getFactorization (arr[i]);
			sort (all (x));
			if (mp.find (x[0]) == mp.end ()) {
				mp[x[0]] = ++c;
				ans[i] = c;
				mp[x[0]] = c;
			} else {
				ans[i] = mp[x[0]];
			}
		}
		pr (*max_element (all (ans)));
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}