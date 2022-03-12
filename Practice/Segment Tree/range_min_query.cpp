/*
				C++
				encoding: UTF-8
				Modified: <07/Oct/2019 04:13:09 PM>

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

#define         ll                    long long
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
#define int long long
const int N = 1e5 + 5;
const int lg = 17;
int arr[N];
int dp[N][lg + 1];
int n;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n) cin >> arr[i];

	fr (i, 0, n) dp[i][0] = arr[i];
	for (int j = 1; j <= lg; ++j) {
		for (int i = 0; i + (1 << j) <= n; ++i) {
			dp[i][j] = min (dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		int ans = 1e18;
		for (int j = lg; j >= 0; j--) {
			if (l + (1 << j) - 1 <= r) {
				ans = min (ans, dp[l][j]);
				l += (1 << j);
			}
		}
		pr (ans);
	}

	return 0;
}
