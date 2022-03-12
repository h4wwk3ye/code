/*
				C++
				encoding:UTF-8
				Modified: <19/May/2019 04:19:08 PM>

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

int n, m;
const int N = 1e3 + 5;
char matrix[N][N];
int dp[N][N];
int ans[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);

	cin >> n >> m;
	fr (i, 0, n) {
		string s;
		cin >> s;
		fr (j, 0, m) matrix[i][j] = s[j];
	}
	fr (i, 0, n) {
		fr (j, 0, m) {
			if (matrix[i][j] == '.') continue;
			if (i == 0 or j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = 1 + min (dp[i][j - 1], min (dp[i - 1][j - 1], dp[i - 1][j]));
		}
	}

	/*fr (i, 0, n) {
		fr (j, 0, m) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	fr (i, 0, n) {
		fr (j, 0, m) {
			ans[dp[i][j]]++;
		}
	}
	dfr (i, N - 1, 0) ans[i] += ans[i + 1];
	fr (i, 2, N) ans[i] += ans[i - 1];
	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		if (x == 0) {
			pr1 (0);
			continue;
		} else {
			pr1 (ans[x]);
		}
	}
	return 0;
}
