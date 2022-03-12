/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 07:27:08 PM>

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

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	int arr[n];
	fr (i, 0, n) cin >> arr[i];
	int k = log (n);

	int dp[n + 5][k + 5];
	reset (dp, 0);

	fr (i, 0, n) dp[i][0] = i;
	fr (j, 1, k + 1) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			if (arr[dp[i][j - 1]] < arr[dp[i + (1 << (j - 1))][j - 1]])
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i + (1 << (j - 1))][j - 1];
		}
	}
	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		int j = log2 (r - l + 1);
		pr (min (arr[dp[l][j]], arr[dp[r - (1 << j) + 1][j]]));
	}
	return 0;
}
