/*
				C++
				encoding: UTF-8
				Modified: <02/Oct/2019 10:18:14 PM>

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

#define         int                    long long
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

const int N = 305;
int n;
int arr[N], pref[N], dp[N][N];

int solve (int i, int j) {
	int& ans = dp[i][j];
	if (ans != 1e18) return ans;
	if (i > n) return -1e18;
	if (i == n) {
		if (j != 0) {
			int k = (i - (j / 2));
			ans = pref[k] - pref[i - j];
			return ans;
		}
		ans = 0;
		return ans;
	}
	// if (j == n + 2)
	// 	return -1e18;
	// else
	// 	return 0;
	int k = (i - (j / 2));
	// pr (i, j, k, pref[k] - pref[i - j], pref[k], pref[i - j]);
	ans = max (solve (i + 2, 2) + (pref[k] - pref[i - j]), solve (i + 2, j + 2));
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 0, n + 1) {
			arr[i] = 0;
			pref[i] = 0;
			fr (j, 0, n + 1) dp[i][j] = 1e18;
		}
		fr (i, 1, n + 1) cin >> arr[i];
		fr (i, 1, n + 1) pref[i] = pref[i - 1] + arr[i];
		int ans = solve (2, 2);
		pr (ans);
	}
	return 0;
}
