/*
				C++
				encoding:UTF-8
				Modified: <03/Jun/2019 12:19:25 PM>

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
int a, b;
const int N = 1e3 + 5;
int dp[N][N][2];

int solve (int x, int y, int c) {
	if (dp[x][y][c] != 0) return dp[x][y][c];
	if (x == 1) return 2;
	if (y == 1) return 1;
	if (c == 0) {
		int g = __gcd (x, y);
		if (g > 1) {
			dp[x][y][c] = min (solve (x, y - 1, 1), solve (x, y / g, 1));
		} else
			dp[x][y][c] = solve (x, y - 1, 1);
	} else {
		int g = __gcd (x, y);
		if (g > 1) {
			dp[x][y][c] = max (solve (x - 1, y, 0), solve (x / g, y, 0));
		} else
			dp[x][y][c] = solve (x - 1, y, 0);
	}
	return dp[x][y][c];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		if (a == 1 and b == 1) {
			pr1 ("Draw");
			continue;
		}
		reset (dp, 0);
		int ans = solve (a, b, 0);
		if (ans == 1)
			pr1 ("Arjit");
		else
			pr1 ("Chandu Don");
	}
	return 0;
}
