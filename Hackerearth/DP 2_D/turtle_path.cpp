/*
				C++
				encoding:UTF-8
				Modified: <11/May/2019 12:33:34 AM>

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

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on
const ll N = 1e3 + 5;
ll matrix[N][N], dp[N][N];
ll n, m;

ve< ll > primes;

void SieveOfEratosthenes (ll n) {
	bool prime[n + 1];
	reset (prime, true);

	for (ll p = 2; p * p <= n; p++) {
		if (prime[p] == true) {
			for (ll i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
	for (ll p = 2; p <= n; p++)
		if (prime[p]) primes.pb (p);
}

ll visited[N][N];

ll path (ll i, ll j) {
	if (visited[i][j] != -1) return visited[i][j];
	if (i == n and j == m) {
		visited[i][j] = 1;
		return 1;
	}
	ll flag = 0;
	if (i + 1 <= n and j + 1 <= m and matrix[i + 1][j + 1] == 1) {
		if (path (i + 1, j + 1)) {
			flag = 1;
		}
	}
	if (i + 1 <= n and matrix[i + 1][j] == 1) {
		if (path (i + 1, j)) {
			flag = 1;
		}
	}
	if (j + 1 <= m and matrix[i][j + 1] == 1) {
		if (path (i, j + 1)) {
			flag = 1;
		}
	}
	return visited[i][j] = flag;
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	SieveOfEratosthenes (1e5 + 5);
	cin >> n >> m;
	fr (i, 1, n + 1) fr (j, 1, m + 1) {
		ll x;
		cin >> x;
		ll k = lower_bound (all (primes), x) - primes.begin ();
		if (primes[k] == x)
			matrix[i][j] = 1;
		else
			matrix[i][j] = 0;
	}

	fr (i, 1, n + 1) {
		if (matrix[i][1] == 1)
			dp[i][1] = 1;
		else
			break;
	}

	fr (i, 1, m + 1) {
		if (matrix[1][i] == 1)
			dp[1][i] = 1;
		else
			break;
	}


	fr (i, 2, n + 1) {
		fr (j, 2, m + 1) {
			if (matrix[i][j] == 0) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1];
			dp[i][j] %= mod;
		}
	}

	/*fr (i, 1, n + 1) {
		fr (j, 1, m + 1) cout << dp[i][j] << " ";
		cout << endl;
	}*/

	pr1 (dp[n][m]);

	if (dp[n][m] == 0) return 0;

	reset (visited, -1);
	path (1, 1);

	/*fr (i, 1, n + 1) {
		fr (j, 1, m + 1) cout << visited[i][j] << " ";
		cout << endl;
	}*/

	ll i = 1, j = 1;
	while (i <= n and j <= m) {
		pr2 (i, j);
		if (i == n and j == m) break;
		if (i + 1 <= n and j + 1 <= m and visited[i + 1][j + 1] == 1) {
			i++;
			j++;
			continue;
		}
		if (i + 1 <= n and visited[i + 1][j] == 1) {
			i++;
			continue;
		}
		if (j + 1 <= m and visited[i][j + 1] == 1) {
			j++;
			continue;
		}
	}

	return 0;
}
