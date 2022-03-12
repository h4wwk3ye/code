/*
				C++
				encoding:UTF-8
				Modified: <13/Apr/2019 12:30:38 AM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on


ll solve (ve< ve< ll > >& dp, ll k, ll start, ll curr) {
	int l = len (dp[0]);
	if (k == 1) return curr & dp[l - start - 1][start];
	ll mx = 0;
	fr (i, 1, l - start - k + 1) {
		ll x = curr & dp[i - 1][start];
		if (x == 0) continue;
		mx = max (mx, solve (dp, k - 1, start + i, x));
	}
	return mx;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll n;
	cin >> n;
	ll arr[n];
	fr (i, 0, n) cin >> arr[i];
	ll tc;
	cin >> tc;
	while (tc--) {
		ll k;
		cin >> k;
		ll t[n];
		fr (i, 0, n) {
			cin >> t[i];
			t[i] *= arr[i];
		}
		ve< ll > final;
		fr (i, 0, n) {
			if (t[i] != 0) final.pb (t[i]);
		}
		if (k > len (final)) {
			pr1 (0);
			continue;
		}
		int l = len (final);
		ve< ve< ll > > dp (l - k + 1);
		dp[0].resize (l);
		fr (i, 0, l) dp[0][i] = final[i];
		fr (i, 1, l - k + 1) {
			dp[i].resize (l - i);
			// pr1 ("here");
			fr (j, 0, len (dp[i])) {
				dp[i][j] = dp[i - 1][j + 1] + dp[0][j];
			}
		}
		// pr1 ("here");
		/*fr (i, 0, n - k + 1) {
			for (auto j : dp[i]) {
				cout << j << " ";
			}
			cout << endl;
		}*/
		pr1 (solve (dp, k, 0, INT_MAX));
	}
	return 0;
}
