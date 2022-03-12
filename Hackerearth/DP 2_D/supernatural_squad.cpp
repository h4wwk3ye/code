/*
				C++
				encoding: UTF-8
				Modified: <01/Jul/2019 06:10:58 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<ll, ll>
#define         len(v)                 ll(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

ll n, k;
ll dp[205];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		if (k > n) {
			pr1 (0);
			continue;
		}
		fill (dp, dp + 205, 0);
		ve< ll > coins;
		fr (i, k, n + 1) coins.pb (i);
		dp[0] = 1;
		for (auto j : coins) {
			fr (i, 1, n + 1) {
				if (i < j) continue;
				dp[i] += dp[i - j];
			}
		}
		pr1 (dp[n]);
	}
	return 0;
}
