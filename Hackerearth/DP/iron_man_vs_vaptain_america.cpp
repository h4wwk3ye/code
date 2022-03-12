/*
				C++
				encoding:UTF-8
				Modified: <12/Apr/2019 10:19:19 AM>

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

const int N = 1e5 + 5;
int n;
ll a[N], b[N], c[N], d[N];
ll dp1[N], dp2[N];


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 0, n) cin >> a[i];
		fr (i, 0, n) cin >> b[i];
		fr (i, 0, n - 1) cin >> c[i];
		fr (i, 0, n - 1) cin >> d[i];
		dp1[0] = a[0], dp2[0] = b[0];
		fr (i, 1, n) {
			dp1[i] = min (dp1[i - 1] + a[i], dp2[i - 1] + a[i] + d[i - 1]);
			dp2[i] = min (dp2[i - 1] + b[i], dp1[i - 1] + b[i] + c[i - 1]);
		}
		pr1 (min (dp1[n - 1], dp2[n - 1]));
	}
	return 0;
}
