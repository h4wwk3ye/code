/*
				C++
				encoding:UTF-8
				Modified: <03/Jun/2019 12:59:38 PM>

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

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int n, k;
	cin >> n >> k;
	int dp[n + 1][k + 1];
	reset (dp, 0);
	fr (i, 0, k + 1) dp[1][i] = 1;
	fr (i, 0, n + 1) dp[i][1] = i;
	fr (i, 2, n + 1) {
		fr (j, 2, k + 1) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			dp[i][j] %= mod;
		}
	}
	int ans = 0;
	fr (i, 1, k + 1) {
		ans += dp[n][i];
		ans %= mod;
	}
	pr1 (ans);
	return 0;
}
