/*
				C++
				encoding:UTF-8
				Modified: <21/Jun/2019 11:21:44 AM>

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
#define		 pii                    pair<ll, ll>
#define		 len(v)                 ll(v.size())
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

const ll N = 605;
ll matrix[N][N], dp[N][N];
ll n, m;

ve< pii > neighbours (ll i, ll j) {
	ve< pii > x;
	if (matrix[i][j] > 0)
		x = {{i + 1, j}, {i, j + 1}, {i + matrix[i][j], j}, {i, matrix[i][j] + j}};
	else
		x = {{i + 1, j}, {i, j + 1}};
	return x;
}

bool check (ll i, ll j) {
	return i >= 0 and i < n and j >= 0 and j < m;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	ll tc;
	cin >> tc;
	while (tc--) {
		ll a, b, c;
		cin >> a >> b >> c;
		matrix[a][b] = c;
	}
	dp[0][0] = 1;
	fr (i, 0, n) {
		fr (j, 0, m) {
			if (matrix[i][j] == -1) continue;
			for (auto p : neighbours (i, j)) {
				if (!check (p.ff, p.ss)) continue;
				if (matrix[p.ff][p.ss] == -1) continue;
				dp[p.ff][p.ss] += dp[i][j] % mod;
				dp[p.ff][p.ss] %= mod;
			}
		}
	}
	pr1 (dp[n - 1][m - 1]);
	return 0;
}
