/*
				C++
				encoding: UTF-8
				Modified: <06/Sep/2019 10:00:44 PM>

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
		ll c, x;
		cin >> c >> x;
		ll ans = 1e18;
		if (x == 1) {
			ans = c;
			pr (ans);
			continue;
		}
		fr (i, 1, min (c + 1, x)) {
			if (i >= ans) break;
			ll curr = i;
			ll j = i;
			while (j <= c) {
				if (j * x > c) break;
				j *= x;
			}
			if (j != c) {
				curr += (c - j);
			}
			// pr (i, curr);
			ans = min (ans, curr);
		}
		pr (ans);
	}
	return 0;
}
