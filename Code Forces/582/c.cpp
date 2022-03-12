/*
				C++
				encoding: UTF-8
				Modified: <30/Aug/2019 08:38:49 PM>

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
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		ll n, m;
		cin >> n >> m;
		ll ans = 0;
		for (ll i = m; i < min (n + 1, 10 * m + 1); i += m) {
			ans += (i % 10);
		}
		if (n <= 10 * m) {
			pr (ans);
			continue;
		}
		ll d = (n / m);
		d /= 10;


		ll tmp = ans * d;

		ll x = (d * 10) * m;
		// pr (tmp, x, n, "x");
		while (x <= n) {
			tmp += (x % 10);
			x += m;
		}


		pr (tmp);
	}
	return 0;
}
