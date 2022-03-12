//#pragma GCC optimize("-O3")

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

const int N = 15;
ve< pii > graph[N];
int vis[N];
int dp[1 << N];
int n, m;

int dfs (int node, int curr) {
	if (curr == (1 << n) - 1) return 0;
	if (dp[curr] < 1e9) return dp[curr];
	for (auto& x : graph[node]) {
		int& to = x.ff;
		if ((curr >> (to - 1)) & 1) continue;
		dp[curr] = min (dp[curr], x.ss + dfs (to, (1 << (to - 1)) | curr));
	}
	return dp[curr];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, m + 1) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb ({v, w});
		graph[v].pb ({u, w});
	}
	int ans = 1e9;

	fr (i, 1, n + 1) {
		fill (dp, dp + (1 << N), 1e9);
		ans = min (ans, dfs (i, 1 << (i - 1)));
	}
	pr (ans);
	return 0;
}