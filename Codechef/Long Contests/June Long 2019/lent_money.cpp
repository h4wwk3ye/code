/*
				C++
				encoding:UTF-8
				Modified: <12/Jun/2019 09:19:53 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		ll arr[n + 1];
		ll total = 0;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			total += arr[i];
		}
		ll k, x;
		cin >> k >> x;
		ll dp[n + 1];
		fr (i, 1, n + 1) dp[i] = (arr[i] ^ x) - arr[i];
		sort (dp + 1, dp + n + 1, greater< ll > ());
		// prv (dp, 1, n + 1);
		if (dp[1] <= 0) {
			pr1 (total);
			continue;
		}
		if (k == n) {
			ll sum = 0;
			fr (i, 1, n + 1) sum += dp[i];
			pr1 (max (total + sum, total));
			continue;
		}
		ll p, sum = 0;
		fr (i, 1, n + 1) {
			if (dp[i] > 0) {
				p = i;
				sum += dp[i];
			} else
				break;
		}
		// pr1 (p);
		if (k % 2 == 1) {
			pr1 (total + sum);
		} else {
			if (p % 2 == 0) {
				pr1 (total + sum);
			} else {
				ll s1 = 0, s2 = 0;
				if (p > 1) fr (i, 1, p) s1 += dp[i];

				if (p < n) fr (i, 1, p + 2) s2 += dp[i];
				ll ans = max (s1, s2);
				// pr2 (s1, s2);
				pr1 (total + ans);
			}
		}
	}
	return 0;
}
