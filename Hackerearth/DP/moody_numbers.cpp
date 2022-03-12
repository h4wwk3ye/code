/*
				C++
				encoding:UTF-8
				Modified: <23/Apr/2019 08:43:07 AM>

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
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 1e6 + 5;
int dp[N];
bool flag[N];
umap< ll, int > mp;

ll sum_digits (ll n) {
	ll r = 0;
	while (n) {
		r = r + n % 10;
		n /= 10;
	}
	return r;
}

bool solve (ll i) {
	if (dp[i] != -1) return dp[i];
	if (mp.find (i) != mp.end ()) {
		return false;
	}
	mp[i] = 1;
	ll j = sum_digits (i * i);
	// mp[j] = 1;
	dp[i] = solve (j);
	return dp[i];
}

void precompute () {
	reset (dp, -1);
	dp[1] = 1;
	dp[4] = 1;
	for (ll i = 1; i < (ll) 1e6 + 1; ++i) {
		mp.clear ();
		if (dp[i] != -1) continue;
		solve (i);
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	precompute ();
	int tc;
	cin >> tc;
	while (tc--) {
		ll n;
		cin >> n;
		while (n > (ll) 1e6) {
			n = sum_digits (n * n);
		}
		if (dp[n] == 1)
			pr1 ("YES");
		else
			pr1 ("NO");
	}
	return 0;
}
