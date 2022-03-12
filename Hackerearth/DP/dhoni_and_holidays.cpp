/*
				C++
				encoding:UTF-8
				Modified: <13/Apr/2019 11:47:07 PM>

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


// clang-format on

const int N = 101;
int n;
int arr[N];
int dp[N][3];

int solve (int index, int prev) {
	if (index == n) return 0;
	if (dp[index][prev] != 1e9) return dp[index][prev];
	if (arr[index] == 0) {
		dp[index][prev] = 1 + solve (index + 1, 0);
	} else if (arr[index] == 1) {
		if (prev == 1)
			dp[index][prev] = 1 + solve (index + 1, 0);
		else
			dp[index][prev] = min (solve (index + 1, arr[index]), 1 + solve (index + 1, 0));
	} else if (arr[index] == 2) {
		if (prev == 2)
			dp[index][prev] = 1 + solve (index + 1, 0);
		else
			dp[index][prev] = min (solve (index + 1, arr[index]), 1 + solve (index + 1, 0));
	} else {
		if (prev == 0)
			dp[index][prev] = min ({solve (index + 1, 1), solve (index + 1, 2), 1 + solve (index + 1, 0)});
		else if (prev == 1)
			dp[index][prev] = min (solve (index + 1, 2), 1 + solve (index + 1, 0));
		else
			dp[index][prev] = min (solve (index + 1, 1), 1 + solve (index + 1, 0));
	}
	return dp[index][prev];
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n) cin >> arr[i];
	fr (i, 0, N) fr (j, 0, 3) dp[i][j] = 1e9;
	pr1 (solve (0, 0));
}
