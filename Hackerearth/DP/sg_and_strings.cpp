/*
				C++
				encoding:UTF-8
				Modified: <24/Apr/2019 07:47:51 AM>

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
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

string a, b;
int m, n;

int solve () {
	int dp[m + 1][n + 1];
	fr (i, 0, m + 1) {
		fr (j, 0, n + 1) {
			dp[i][j] = 0;
		}
	}
	fr (i, 0, n + 1) dp[0][i] = 0;
	fr (i, 0, m + 1) dp[i][0] = 1;


	fr (i, 1, m + 1) {
		fr (j, 1, n + 1) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
			} else {
				dp[i][j] = dp[i][j - 1] % mod;
			}
		}
	}

	dp[m][n] += mod;
	return dp[m][n] % mod;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> b >> a;
	m = len (b);
	n = len (a);
	pr1 (solve ());
	return 0;
}
