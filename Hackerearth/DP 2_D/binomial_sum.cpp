/*
				C++
				encoding:UTF-8
				Modified: <15/May/2019 05:51:12 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
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

ll a, b, c, d;
const int N = 1e3 + 5;
ll dp[N][N];

void ncr (ll n, ll r) {
	dp[0][0] = 1;
	ll i, j;
	fr (i, 1, 1001) {
		fr (j, 0, i + 1) {
			if (j == 0)
				dp[i][j] = 1;
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
				dp[i][j] %= mod;
			}
		}
	}

	fr (i, 1, 1001) {
		fr (j, i + 1, 1001) {
			dp[i][j] = i * j;
			dp[i][j] %= mod;
		}
	}

	fr (i, 0, 1001) {
		fr (j, 1, 1001) {
			dp[i][j] = dp[i][j] * dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}
}

int32_t main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	ll tc;
	cin >> tc;
	ncr (1000, 1000);

	while (tc--) {
		cin >> a >> b >> c >> d;
		ll ans = 0;
		fr (i, a, b + 1) {
			ll curr = dp[i][d];
			if (c > 0) {
				curr = (curr * (powermod (dp[i][c - 1], mod - 2, mod) % mod));
				curr %= mod;
			}
			ans += curr;
			ans %= mod;
		}
		pr1 (ans);
	}
	return 0;
}
