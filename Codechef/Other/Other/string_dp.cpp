/*
				C++
				encoding: UTF-8
				Modified: <08/Sep/2019 03:38:55 PM>

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
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on
#define int long long
int func (int k, vector< char > ch_arr, int n) {
	int ans = 0;
	const int mod = 1e9 + 7;
	int dp[n + 5][2];
	dp[1][0] = k;
	dp[1][1] = k;
	for (int i = 2; i <= n; i++) {
		if (i & 1) {
			dp[i][0] = (((k - 1) * dp[i - 1][0]) % mod + (k * dp[i - 1][1]) % mod) % mod;
			dp[i][1] = dp[i][0];
		} else {
			dp[i][0] = ((k - 1) * dp[i - 1][0]) % mod;
			dp[i][1] = ((26 - k) * dp[i - 1][1]) % mod;
		}
	}
	if (n & 1) {
		ans = dp[n][0];
		ans %= mod;
	} else {
		ans = dp[n][0] + dp[n][1];
		ans %= mod;
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int N;
		cin >> N;
		int K;
		cin >> K;
		vector< char > ch_arr (K);
		fr (i, 0, K) cin >> ch_arr[i];
		int out_;
		out_ = func (K, ch_arr, N);
		cout << out_ << "\n";
	}
	return 0;
}
