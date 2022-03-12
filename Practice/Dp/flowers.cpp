/*
				C++
				encoding: UTF-8
				Modified: <04/Oct/2019 07:43:02 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 1e5 + 5;
int dp[N];
const int mod = 1e9 + 7;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int t, k;
	cin >> t >> k;

	dp[0] = 1;
	fr (i, 1, N - 2) {
		if (i >= k) {
			dp[i] += (dp[i - 1] + dp[i - k]) % mod;
		} else {
			dp[i] += dp[i - 1];
			dp[i] %= mod;
		}
	}
	dp[0] = 0;
	fr (i, 1, N) {
		dp[i] += dp[i - 1];
		dp[i] %= mod;
	}
	while (t--) {
		int a, b;
		cin >> a >> b;
		int ans = dp[b] - dp[a - 1] + mod;
		ans %= mod;
		pr (ans);
	}

	return 0;
}
