/*
				C++
				encoding:UTF-8
				Modified: <20/Apr/2019 10:00:52 AM>

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
const int N = 1e4 + 5;
int dp[2][N];

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x;
		cin >> n >> x;
		int arr[n];
		ll sum = 0;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			sum += arr[i];
		}

		if (sum <= x) {
			pr1 ("YES");
			continue;
		}
		fr (i, 0, x + 1) dp[0][i] = 0;
		fr (i, 1, n + 1) {
			fr (j, 0, x + 1) {
				dp[i % 2][j] = dp[(i - 1) % 2][j];
				if (j >= arr[i])
					dp[i % 2][j] = max (dp[i % 2][j], dp[(i - 1) % 2][j - arr[i]] + arr[i]);
			}
		}

		if (sum - dp[n % 2][x] <= x)
			pr1 ("YES");
		else
			pr1 ("NO");
	}
	return 0;
}
