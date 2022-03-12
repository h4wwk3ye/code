/*
				C++
				encoding:UTF-8
				Modified: <10/May/2019 05:23:33 PM>

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

const int N = 105;
int x[N], y[N];
int n, p;
int dp[N][10005];

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (dp, 0);
		int money = 0;
		cin >> n >> p;
		fr (i, 1, n + 1) {
			int l, m;
			cin >> l >> m;
			l -= m;
			x[i] = l;
			y[i] = m;
		}

		fr (i, 1, n + 1) {
			fr (j, 1, p + 1) {
				if (j >= y[i])
					dp[i][j] = max (dp[i - 1][j], dp[i - 1][j - y[i]] + x[i]);
				else
					dp[i][j] = dp[i - 1][j];
			}
		}

		/*fr (i, 1, n + 1) {
			fr (j, 1, p + 1) cout << dp[i][j] << " ";
			cout << endl;
		}*/

		int mx = dp[n][p];
		int i = n, j = p;
		while (j >= 0 and dp[i][j] == mx)
			j--;
		pr2 (j + 1, mx + p);
	}
	return 0;
}
