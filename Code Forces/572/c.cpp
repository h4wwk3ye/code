/*
				C++
				encoding: UTF-8
				Modified: <30/Jul/2019 06:49:33 PM>

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

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

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

	int k = log2 (n);

	int dp[n + 5][k + 5], chk[n + 5][k + 5];
	reset (dp, 0);
	reset (chk, 0);

	int ans = 0;
	fr (i, 0, n) dp[i][0] = arr[i];
	fr (j, 1, k + 1) {
		for (ll i = 0; i + (1 << j) <= n; i++) {
			dp[i][j] = dp[i][j - 1] + dp[i + (1 << (j - 1))][j - 1];
			chk[i][j] = chk[i][j - 1] + chk[i + (1 << (j - 1))][j - 1];

			if (dp[i][j] >= 10) {
				chk[i][j]++;
				dp[i][j] -= 10;
			}
		}
	}
	/*fr (i, 0, n + 1) {
		fr (j, 0, k + 1) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	fr (i, 0, n + 1) {
		fr (j, 0, k + 1) {
			cout << chk[i][j] << " ";
		}
		cout << endl;
	}*/

	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		ll x = r - l + 1;
		x = log2 (x);
		pr (chk[l - 1][x]);
	}

	return 0;
}
