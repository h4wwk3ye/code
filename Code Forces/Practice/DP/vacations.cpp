/*
				C++
				encoding:UTF-8
				Modified: <08/May/2019 07:37:57 PM>

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

const int N = 105;
int arr[N];
int n;

int dp[N][3];
int inf = 1e9;

int recurse (int i, int prev) {
	if (i == n) return 0;
	if (dp[i][prev] != inf) return dp[i][prev];
	if (prev == 0) {
		if (arr[i] == 0)
			dp[i][prev] = 1 + recurse (i + 1, 2);
		else if (arr[i] == 2)
			dp[i][prev] = 1 + recurse (i + 1, 2);
		else
			dp[i][prev] = min (recurse (i + 1, 1), 1 + recurse (i + 1, 2));
	}

	else if (prev == 1) {
		if (arr[i] == 0)
			dp[i][prev] = 1 + recurse (i + 1, 2);
		else if (arr[i] == 1)
			dp[i][prev] = 1 + recurse (i + 1, 2);
		else
			dp[i][prev] = min (recurse (i + 1, 0), 1 + recurse (i + 1, 2));
	}

	else {
		if (arr[i] == 0)
			dp[i][prev] = 1 + recurse (i + 1, 2);
		else if (arr[i] == 1)
			dp[i][prev] = min (recurse (i + 1, 1), 1 + recurse (i + 1, 2));
		else if (arr[i] == 2)
			dp[i][prev] = min (recurse (i + 1, 0), 1 + recurse (i + 1, 2));
		else
			dp[i][prev] = min (min (recurse (i + 1, 0), recurse (i + 1, 1)), 1 + recurse (i + 1, 2));
	}
	return dp[i][prev];
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	fr (i, 0, N) fr (j, 0, 3) dp[i][j] = inf;
	cin >> n;
	fr (i, 0, n) cin >> arr[i];
	recurse (0, 2); // 0 gym, 1 vacation, 2 rest
	pr1 (min (min (dp[0][0], dp[0][1]), dp[0][2]));
	return 0;
}
