/*
				C++
				encoding:UTF-8
				Modified: <15/May/2019 06:17:47 PM>

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

const int N = 1e3 + 5;
ll matrix[N][N];
int n, m;
int x_1, y_1, x_2, y_2;
ll dp[N][N];

void solve (int n, int m) {
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			dp[i][j] = dp[i][j - 1] + matrix[i][j];
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	fr (i, 1, n + 1) fr (j, 1, m + 1) cin >> matrix[i][j];
	solve (n, m);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		ll ans = 0;
		fr (i, x_1, x_2 + 1) {
			ans += (dp[i][y_2] - dp[i][y_1 - 1]);
		}
		pr1 (ans);
	}

	return 0;
}
