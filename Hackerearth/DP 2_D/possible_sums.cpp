/*
				C++
				encoding:UTF-8
				Modified: <21/Jun/2019 11:54:26 AM>

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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n + 1];
		int dp[n + 1][(int) 1e4 + 5];
		reset (dp, 0);
		set< int > s;
		fr (i, 1, n + 1) {
			cin >> arr[i];
		}
		dp[0][0] = 1;
		fr (i, 1, n + 1) {
			fr (j, 0, 1e4 + 1) {
				if (j < arr[i])
					dp[i][j] = (dp[i - 1][j] == 1);
				else
					dp[i][j] = (dp[i - 1][j - arr[i]] == 1 or dp[i - 1][j] == 1);
				if (dp[i][j]) s.insert (j);
			}
		}
		pr1 (len (s));
	}
	return 0;
}
