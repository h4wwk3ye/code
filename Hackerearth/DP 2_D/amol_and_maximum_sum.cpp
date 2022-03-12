/*
				C++
				encoding:UTF-8
				Modified: <23/May/2019 12:04:36 PM>

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

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int n, k, p;
const int N = 1e5 + 5;
ll arr[N];
ve< ve< ll > > dp;

ll solve (ll i, ll c) {
	if (c == k) return 0;
	if (c > k) return -1e18;
	if (i >= n) return 0;

	if (dp[i][c] != 0) return dp[i][c];

	dp[i][c] =
	max (solve (i + 1, c),
		 max (solve (i + 1 + p + 1, c + 2) + arr[i] + arr[i + 1], solve (i + p + 1, c + 1) + arr[i]));

	return dp[i][c];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> k >> p;

	dp.resize (n);
	fr (i, 0, n) {
		dp[i].resize (k);
		fill (all (dp[i]), 0);
		cin >> arr[i];
	}
	// fr (i, 0, n) cin >> arr[i];
	pr1 (solve (0, 0));
	return 0;
}
