/*
				C++
				encoding:UTF-8
				Modified: <06/Jun/2019 11:23:54 PM>

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
	// ios_base::sync_with_stdio (false), cin.tie (0);
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n, x;
		cin >> n >> x;
		if (x == 1) {
			pr1 (0);
			continue;
		}
		ll low = 2, high = (2 << n - 1) / 2 + 1;
		ll ans = 0;
		ll tmp = n - 2;
		ll curr = 1;
		while (tmp) {
			curr *= 2;
			tmp--;
		}
		curr /= 2;
		while (1) {
			ans++;
			if (low == x or high == x) break;
			// pr3 (low, high, curr);
			if (x < high) {
				high = low + 2 * curr;
				low++;
				curr /= 2;
			} else {
				low = high + 1;
				high = high + 2 * curr;
				curr /= 2;
			}
		}
		pr1 (ans);
	}
	return 0;
}
