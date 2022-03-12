//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Dec/19 06:05:23 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 5e3 + 5;
ve< int > graph[N];
int dp[N][N];
int n, m, k;
int a[N], b[N], c[N];
int def[N], com[N], vis[N];

int solve (int i, int j) {
	if (i > n) return 0;

	int& ans = dp[i][j];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	if (j < a[i]) {
		ans = -1e18;
		return ans;
	} else {
		com[i] = 1;
		ans = solve (i + 1, j + b[i] - 1);
		// k += b[i] - 1;
		if (ans != -1e18) {
			def[i] = 1;
			if (!vis[i]) ans += c[i];
			vis[i] = 1;
			for (int x : graph[i]) {
				if (!vis[x]) {
					vis[x] = 1;
					ans += c[x];
				}
			}
			return ans;
		} else {
			// k -= (b[i] - 1);
			ans = solve (i + 1, j + b[i]);
			return ans;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> k;
	fr (i, 1, n + 1) cin >> a[i] >> b[i] >> c[i];
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
	}

	reset (dp, -1);
	int ans = solve (1, k);

	if (ans == -1e18) {
		pr (-1);
		return 0;
	}
	pr (ans);
	return 0;
}