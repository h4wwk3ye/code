/*
				C++
				encoding:UTF-8
				Modified: <22/May/2019 07:08:15 PM>

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

int matrix[25][25];

int n, ans;

void solve (int i, int dp[25][25]) {
	pr1 (i);
	if (i == n + 1) {
		int cnt = 0;
		fr (i, 1, n + 1) {
			fr (j, 1, n + 1) {
				if (dp[i][j]) {
					cnt++;
					break;
				}
			}
		}
		if (cnt == n) ans++;
		return;
	}

	fr (j, 1, n + 1) {
		if (matrix[i][j]) {
			bool flag = true;
			fr (k, 1, n + 1) {
				if (dp[k][j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				// pr1 ("here");
				int tmp[25][25];
				fr (l, 1, 25) fr (m, 1, 25) tmp[l][m] = dp[l][m];
				tmp[i][j] = 1;
				solve (i + 1, tmp);
				solve (i + 1, dp);
			}
		}
	}
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, n + 1) fr (j, 1, n + 1) {
			cin >> matrix[i][j];
		}
		int dp[25][25];
		reset (dp, 0);
		solve (1, dp);
		pr1 (ans);
	}
	return 0;
}
