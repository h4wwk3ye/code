/*
				C++
				encoding: UTF-8
				Modified: <29/Jun/2019 06:41:33 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         pq                     priority_queue
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<ll, ll>
#define         len(v)                 ll(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	ll tc;
	cin >> tc;
	while (tc--) {
		ll n, m, k;
		cin >> m >> n >> k;
		if (m * n < k) {
			pr1 ("0.000 0");
			continue;
		}
		long double dp[m + 1][(n * m) + 1];
		reset (dp, 0);
		fr (i, 1, n + 1) dp[1][i] = 1;
		fr (i, 2, m + 1) {
			fr (j, i, n * m + 1) {
				if (j > n * i) break;
				dfr (l, j - 1, max (0LL, j - n - 1)) {
					dp[i][j] += dp[i - 1][l];
				}
			}
		}

		long double cnt = 0;
		fr (i, 1, n * m + 1) cnt += dp[m][i];
		long double prob = (long double) dp[m][k] / cnt;
		if (prob == 0) {
			pr1 ("0.000 0");
			continue;
		}
		int p = 0;
		while (prob < 1) {
			prob *= 10;
			p++;
		}
		cout << fixed << setprecision (3) << prob << " " << p << endl;
	}
	return 0;
}
