/*
				C++
				encoding: UTF-8
				Modified: <28/Aug/2019 11:51:18 AM>

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
#define         pii                    pair<ll, ll>
#define         len(v)                 ll(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

ll n, m;

ve< ll > b, c;
ve< ve< ll > > dp;

ll solve (ll i, ll j) {
	if (i == n) return 0;
	if (j == m) return 1e18;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = min (abs (b[i] - c[j]) + solve (i + 1, j + 1), solve (i, j + 1));
	return dp[i][j];
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	b.resize (n);
	c.resize (m);
	dp.resize (n, ve< ll > (m, -1));

	fr (i, 0, n) cin >> b[i];
	fr (i, 0, m) cin >> c[i];
	sort (all (b));
	sort (all (c));
	pr (solve (0, 0));
	/*fr (i, 0, n) {
		fr (j, 0, m) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	return 0;
}
