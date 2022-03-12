/*
				C++
				encoding:UTF-8
				Modified: <03/Jun/2019 02:53:53 PM>

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

const int N = 1e3 + 5;
int matrix[N][N];
int dp[N][N];
int n;

bool check (int i, int j) {
	return (i >= 1 and i <= n and j >= 1 and j <= n);
}

ve< pii > neighbours (int i, int j) {
	ve< pii > x = {{i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}};
	return x;
}

int solve (int i, int j) {
	if (dp[i][j] != 0) return dp[i][j];
	int curr = 1;
	for (auto x : neighbours (i, j)) {
		if (check (x.ff, x.ss) and matrix[x.ff][x.ss] < matrix[i][j]) {
			curr += solve (x.ff, x.ss);
			curr %= mod;
		}
	}
	dp[i][j] = curr;
	return curr;
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 1, n + 1) fr (j, 1, n + 1) cin >> matrix[i][j];
	int ans = 0;
	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			ans += solve (i, j);
			ans %= mod;
		}
	}
	pr1 (ans);
	return 0;
}
