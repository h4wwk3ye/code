/*
				C++
				encoding: UTF-8
				Modified: <28/Sep/2019 06:27:42 PM>

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
#define         pii                    pair<ll, ll>
#define         len(v)                 (v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

bool prime (ll number) {
	if (number < 2) return false;
	if (number % 2 == 0) return (number == 2);
	ll root = sqrt (number);
	for (ll i = 3; i <= root; i += 2) {
		if (number % i == 0) return false;
	}
	return true;
}

ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}

set< ll > factors1;

void commDiv1 (ll n) {
	ll result = 0;
	for (ll i = 1; i <= 2 * sqrt (n); i++) {
		if (n % i == 0) {
			if (n / i == i) {
				factors1.insert (i);
			} else {
				factors1.insert (i);
				factors1.insert (n / i);
			}
		}
	}
}
set< ll > factors2;

void commDiv2 (ll n) {
	ll result = 0;
	for (ll i = 1; i <= 2 * sqrt (n); i++) {
		if (n % i == 0) {
			if (n / i == i) {
				factors2.insert (i);
			} else {
				factors2.insert (i);
				factors2.insert (n / i);
			}
		}
	}
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	ll a, b;
	cin >> a >> b;
	commDiv1 (a);
	commDiv2 (b);


	ve< ll > arr;

	for (auto i : factors1) {
		if (factors2.find (i) != factors2.end ()) {
			arr.pb (i);
		}
	}

	int ans = 0;

	sort (all (arr));
	set< ll > s;

	fr (i, 0, len (arr)) {
		int f = 1;
		for (auto j : s) {
			if (gcd (arr[i], j) != 1) {
				f = 0;
				break;
			}
		}
		if (f) {
			ans++;
			s.insert (arr[i]);
		}
	}
	pr (ans);

	return 0;
}
