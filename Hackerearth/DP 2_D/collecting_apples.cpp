/*
				C++
				encoding:UTF-8
				Modified: <09/Jun/2019 06:30:04 PM>

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
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

int n, p;
const int N = 1e3 + 5;
int milk[N], apples[N];
int dp[N][N];

int solve (int i, int j) {
	if (i > n) return 0;
	if (j < 0) return 0;
	if (dp[i][j]) return dp[i][j];
	dp[i][j] = max (solve (i + 1, j - 1) + apples[i], solve (i + 1, min (j - 1 + milk[i], n)));
	return dp[i][j];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		int total = 0;
		reset (dp, 0);
		cin >> n >> p;
		fr (i, 1, n + 1) cin >> milk[i];
		fr (i, 1, n + 1) {
			cin >> apples[i];
			total += apples[i];
		}
		if (p == 0) {
			pr1 (0);
			continue;
		}
		if (p > n) {
			pr1 (total);
			continue;
		}
		int ans = solve (1, p - 1);
		pr1 (ans);
	}

	return 0;
}
