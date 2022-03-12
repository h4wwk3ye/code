/*
				C++
				encoding:UTF-8
				Modified: <20/Apr/2019 08:43:24 AM>

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
int n;
const int N = 1e3 + 5;
int arr[N][N];
int dp[N][N];

ll solve (int row, int col) {
	if (row == -1) return 0;
	if (dp[row][col] != 0) return dp[row][col];
	int d[3] = {-1, 0, 1};
	ll m = 0;
	fr (i, 0, 3) {
		if (col + d[i] >= 0 and col + d[i] < n) {
			m = max (m, arr[row][col] + solve (row - 1, col + d[i]));
		}
	}
	dp[row][col] = m;
	return m;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n) {
		fr (j, 0, n) {
			cin >> arr[i][j];
		}
	}
	ll mx = 0;
	fr (i, 0, n) {
		mx = max (mx, solve (n - 1, i));
	}
	pr1 (mx);
	return 0;
}
