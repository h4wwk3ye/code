/*
				C++
				encoding:UTF-8
				Modified: <10/May/2019 10:06:10 PM>

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

const int N = 300;
int arr[N];
int n, m;
int inf = 1e9;
int dp[20][255];

int solve (int i, int j) {
	if (i == m)
		if (j == n)
			return 0;
		else
			return inf;
	if (j == n) return 0;

	if (dp[i][j] != 0) return dp[i][j];

	int ans = solve (i + 1, j);
	int total = 0;
	fr (k, j, n) {
		total += arr[k];
		ans = min (ans, max (total, solve (i + 1, k + 1)));
	}
	dp[i][j] = ans;
	return ans;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> m;
	cin >> n;
	fr (i, 0, n) cin >> arr[i];
	pr1 (solve (0, 0));
	return 0;
}
