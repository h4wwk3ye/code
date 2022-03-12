/*
				C++
				encoding:UTF-8
				Modified: <12/Jun/2019 01:57:50 PM>

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
	// ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n + 1];
		int total = 0;
		fr (i, 1, n + 1) {
			cin >> arr[i];
			total += arr[i];
		}
		int k, x;
		cin >> k >> x;
		int dp[n + 1];
		fr (i, 1, n + 1) dp[i] = (arr[i] ^ x) - arr[i];
		sort (dp + 1, dp + n + 1, greater<> ());
		// prv (dp, 1, n + 1);
		int i = 1;
		while (i + k - 1 <= n) {
			int flag = 0, idx, sum = 0;
			fr (j, i, i + k) {
				if (dp[j] < 0) {
					if (!flag) idx = j;
					flag = 1;
					sum += dp[j];
				}
				if (!flag) curr += dp[j];
			}
			i += k;
			if (flag == 1) {
				if (idx + k - 1 <= n) {
				}
			}
			// pr2 (sum2, sum3);
			if (curr <= 0)
				break;
			else
				total += curr;
		}
		pr1 (total);
	}
	return 0;
}
