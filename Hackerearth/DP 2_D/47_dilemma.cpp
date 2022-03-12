/*
				C++
				encoding:UTF-8
				Modified: <23/May/2019 06:13:05 PM>

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

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

int n, x;
const int N = 1e3 + 5;
int arr[N][3], dp[N][3];

int solve (int i, int p = 3) {
	if (i == n + 1) return 0;
	if (dp[i][p] != 1e9) return dp[i][p];
	if (i == 1) {
		return min (arr[i][0] + solve (i + 1, 0),
					min (arr[i][1] + solve (i + 1, 1), arr[i][2] + solve (i + 1, 2)));
	}
	if (p == 0) {
		dp[i][0] = min (dp[i][0], min (arr[i][1] + solve (i + 1, 1), arr[i][2] + solve (i + 1, 2)));
	} else if (p == 1) {
		dp[i][1] = min (dp[i][1], min (arr[i][0] + solve (i + 1, 0), arr[i][2] + solve (i + 1, 2)));
	} else if (p == 2) {
		dp[i][2] = min (dp[i][2], min (arr[i][0] + solve (i + 1, 0), arr[i][1] + solve (i + 1, 1)));
	}
	return dp[i][p];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> x;
		fr (i, 1, n + 1) fr (j, 0, 3) cin >> arr[i][j];

		fr (i, 0, N) fr (j, 0, 3) dp[i][j] = 1e9;

		int ans = solve (1);
		if (ans > x) {
			pr1 ("NO");
			pr1 (ans - x);
		}

		else {
			pr1 ("YES");
			pr1 (x - ans);
		}
	}
	return 0;
}
