/*
				C++
				encoding: UTF-8
				Modified: <19/Jul/2019 09:43:16 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#	include <prettyprint.hpp>
#endif

using namespace std;

// clang-format off

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
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"

void print (string sep = "\n") {
    cout << sep;
}

template < typename T, typename... TAIL > void print (const T& t, TAIL... tail) {
    cout << t << " ";
    print (tail...);
}

// clang-format on

ll n;
const int N = 805;
ll arr[N], prefix[N], dp[N][N];

void init () {
	reset (arr, 0);
	reset (dp, -1);
	reset (prefix, 0);
}

ll sum (int l, int r) {
	if (l >= r) return 0;
	return prefix[r] - prefix[l - 1];
}

ll solve (ll i, ll j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) {
		dp[i][j] = arr[i];
	} else {
		dp[i][j] = 1e18;
		fr (k, i, j) {
			dp[i][j] = min (dp[i][j], solve (i, k) + solve (k + 1, j) + prefix[j] - prefix[i - 1]);
		}
	}
	return dp[i][j];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		fr (i, 1, n + 1) {
			cin >> arr[i];
			arr[i + n] = arr[i];
		}
		fr (i, 1, 2 * n + 1) {
			prefix[i] = arr[i] + prefix[i - 1];
		}
		ll ans = 1e18;
		fr (i, 1, n + 1) {
			ans = min (ans, solve (i, i + n - 1));
		}
		print (ans);
	}
	return 0;
}
