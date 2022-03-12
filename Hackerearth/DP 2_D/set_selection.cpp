/*
				C++
				encoding:UTF-8
				Modified: <23/May/2019 06:59:36 PM>

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

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on

const int N = 105;
int arr[N];
int dp[N][(int) 1e5 + 5];
int n;

void solve (int i, int c) {
	if (i == n + 1) return;
	if (dp[i][c] and dp[i][c + arr[i]]) return;
	dp[i][c] = 1;
	dp[i][c + arr[i]] = 1;
	solve (i + 1, c);
	solve (i + 1, c + arr[i]);
}

signed main () {
	cin >> n;
	int total = 0;
	fr (i, 1, n + 1) {
		cin >> arr[i];
		total += arr[i];
	}
	solve (1, 0);
	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		string ans = "No";
		fr (i, 1, n + 1) if (dp[i][x]) {
			ans = "Yes";
			break;
		}
		pr1 (ans);
	}
	return 0;
}
