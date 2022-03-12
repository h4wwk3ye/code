/*
				C++
				encoding:UTF-8
				Modified: <26/May/2019 10:51:04 AM>

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

int n, x;
const int N = 1e3 + 5;
int A[N], B[N];
int dp[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> x >> n;
	fr (i, 1, n + 1) {
		cin >> A[i];
		cin >> B[i];
	}
	fr (i, 1, x + 1) {
		fr (j, 1, n + 1) {
			if (A[j] > i) continue;
			dp[i] = max (dp[i], B[j] + dp[i - A[j]]);
		}
	}
	pr1 (dp[x]);
	return 0;
}
