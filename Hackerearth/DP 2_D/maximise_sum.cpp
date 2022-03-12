/*
				C++
				encoding:UTF-8
				Modified: <14/May/2019 06:27:11 PM>

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

const ll N = 1e3 + 5;
ll arr[N];
ll n;
ll dp[N][N];

ll solve (ll i, ll j) {
	if (i > j) return 0;
	if (i == j) return arr[i];
	if (dp[i][j]) return dp[i][j];
	ll a = arr[i] * arr[i + 1];
	ll b = arr[i];
	ll c = arr[j] * arr[j - 1];
	ll d = arr[j];
	dp[i][j] = max (max (a + solve (i + 2, j), c + solve (i, j - 2)),
					max (b + solve (i + 1, j), d + solve (i, j - 1)));
	return dp[i][j];
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	freopen ("inp.txt", "r", stdin);
	cin >> n;
	fr (i, 0, n) cin >> arr[i];
	pr1 (solve (0, n - 1));
	return 0;
}
