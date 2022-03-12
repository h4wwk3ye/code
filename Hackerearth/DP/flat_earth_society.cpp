/*
				C++
				encoding:UTF-8
				Modified: <12/Apr/2019 07:56:41 AM>

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
#define		 pr1(x)                 cout<<x<<"\n";
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n";
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
const int N = 1e5 + 1;
int arr[N];
int aux[N];
int dp[N];


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		reset (aux, 0);
		reset (dp, 0);
		int n, l, r;
		cin >> n >> l >> r;
		l = min (l, r);
		fr (i, 1, n + 1) {
			cin >> arr[i];
			aux[arr[i]]++;
		}
		fr (i, 1, 1e5 + 1) {
			if (i - l <= 0)
				dp[i] = max (dp[i - 1], i * aux[i]);
			else
				dp[i] = max (dp[i - 1], i * aux[i] + dp[i - l - 1]);
		}
		pr1 (dp[N - 1]);
	}
	return 0;
}
