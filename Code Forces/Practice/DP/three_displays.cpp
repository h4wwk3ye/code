/*
				C++
				encoding:UTF-8
				Modified: <11/May/2019 09:17:42 PM>

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

const int N = 3e3 + 5;
int s[N], c[N];
int n;


/*int solve (int i, int cnt, int pr) {
	if (cnt == 3) return 0;
	if (i == n) {
		if (cnt == 3) return 0;
		return 1e9;
	}
	if (s[i] <= pr) return (solve (i + 1, cnt, pr));
	return min (solve (i + 1, cnt, pr), solve (i + 1, cnt + 1, s[i]) + c[i]);
}*/

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) cin >> s[i];
	fr (i, 1, n + 1) cin >> c[i];

	// int ans = solve (0, 0, 0);
	int dp[n + 1];
	fill (dp, dp + n + 1, 1e9);
	fr (i, 1, n + 1) {
		fr (j, i + 1, n + 1) {
			if (s[j] > s[i]) dp[i] = min (dp[i], c[j]);
		}
	}
	int ans = 1e9;
	fr (i, 1, n + 1) {
		fr (j, i + 1, n + 1) {
			if (s[j] > s[i]) ans = min (ans, dp[j] + c[i] + c[j]);
		}
	}
	if (ans >= 1e9)
		pr1 (-1);
	else
		pr1 (ans);
	return 0;
}
