/*
				C++
				encoding:UTF-8
				Modified: <16/Apr/2019 09:38:02 PM>

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

const int N = 2e5 + 5;
int n, ba, acc;
int s[N];
int dp[N][2];


int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> ba >> acc;
	fr (i, 1, n + 1) cin >> s[i];
	int ans = 0;
	int b = ba;
	int a = acc;
	fr (i, 1, n + 1) {
		if (a == acc) {
			ans++;
			a--;
			continue;
		}
		if (s[i] == 1) {
			if (b > 0) {
				b--;
				ans++;
				a++;
			} else {
				if (a > 0) {
					a--;
					ans++;
				} else
					break;
			}
		} else {
			if (a > 0) {
				a--;
				ans++;
			} else {
				if (b > 0) {
					b--;
					ans++;
				} else
					break;
			}
		}
	}
	pr1 (ans);
	return 0;
}
