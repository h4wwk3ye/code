/*
				C++
				encoding: UTF-8
				Modified: <26/Jul/2019 05:21:18 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

#define         int                    long long
#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

int n, m;
const int N = 505;
int arr[N], dp[N][2 * N], chk[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, n + 1) cin >> arr[i];

	fr (i, 0, arr[1] + 1) dp[1][i]++;

	fr (i, 2, n + 1) {
		fr (j, 0, 2 * 505) chk[j] = dp[i - 1][j];

		fr (j, 1, arr[i] + 1) {
			fr (k, 0, 2 * 505) {
				if (dp[i - 1][k]) {
					dp[i][k ^ j] = (chk[k ^ j] + dp[i - 1][k]) % mod;
					chk[k ^ j] = dp[i][k ^ j];
				}
			}
		}
	}

	fr (i, 0, m + 1) cout << dp[n][i] << " ";
	return 0;
}
