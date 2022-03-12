/*
				C++
				encoding:UTF-8
				Modified: <20/Apr/2019 08:29:58 AM>

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
//#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int a;
ve< int > pumps;
int l, m;
int ans;
const int N = 1e6 + 5;
int dp[N];


int main () {
	// freopen ("inp.txt", "r", stdin);
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a;
		cin >> l;
		cin >> m;
		pumps.resize (m + 1);
		fr (i, 1, m + 1) cin >> pumps[i];

		reset (dp, 0);

		pumps[0] = 0;
		sort (all (pumps));

		dp[0] = 1;

		int j = 0;
		ll sum = 1;

		fr (i, 1, m + 1) {
			while (j < i and pumps[i] - pumps[j] > l) {
				j++;
				sum = (sum - dp[j - 1] + mod) % mod;
			}
			dp[i] = sum;
			sum = (sum + dp[i]) % mod;
		}

		if (pumps[m] == a)
			pr1 (dp[m]);
		else {
			while (j <= m and a - pumps[j] > l) {
				j++;
				sum = (sum - dp[j - 1] + mod) % mod;
			}
			pr1 (sum);
		}
	}
	return 0;
}
