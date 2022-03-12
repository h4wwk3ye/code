/*
				C++
				encoding: UTF-8
				Last Modified: 22/Oct/2019 09:54:02 PM
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 2e5 + 5;
int a[N], b[N];
int dp[N][2];
int n, c;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> c;
	fr (i, 1, n) cin >> a[i];
	fr (i, 1, n) cin >> b[i];
	dp[1][0] = 0;
	dp[1][1] = c;
	fr (i, 2, n + 1) {
		dp[i][0] = min (dp[i - 1][0] + a[i - 1], dp[i - 1][1] + a[i - 1]);
		dp[i][1] = min (dp[i - 1][0] + c + b[i - 1], dp[i - 1][1] + b[i - 1]);
	}
	fr (i, 1, n + 1) {
		cout << (min (dp[i][0], dp[i][1])) << " ";
	}
	return 0;
}
