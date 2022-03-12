/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/20 07:56:34 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

// https://cp-algorithms.com/graph/lca_binary_lifting.html

const int N = 1e5 + 5;
int n, q, r;
array< vector< pair< int, int > >, N > adj;

int dp[N][20];
int pre[N], post[N], t, sum[N];

int dfs (int node, int parent, int curr) {
	pre[node] = ++t;
	dp[node][0] = parent;
	sum[node] = curr;
	for (int i = 1; i < 20; ++i) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (auto& x : adj[node]) {
		int& to = x.first;
		if (to == parent) continue;
		dfs (to, node, curr + x.second);
	}

	post[node] = ++t;
}

bool is_ancestor (int u, int v) {
	return pre[u] <= pre[v] and post[v] <= post[u];
}

int lca (int u, int v) {
	if (is_ancestor (u, v)) return u;
	if (is_ancestor (v, u)) return v;
	for (int i = 19; i >= 0; --i) {
		if (!is_ancestor (dp[u][i], v)) {
			u = dp[u][i];
		}
	}
	return dp[u][0];
}

void init () {
	for (int i = 1; i <= n; ++i) {
		adj[i].clear ();
		pre[i] = post[i] = sum[i] = 0;
		for (int j = 0; j < 20; ++j)
			dp[i][j] = 0;
	}
	t = 0;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> q >> r;
		init ();
		for (int i = 1; i < n; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back ({v, w});
			adj[v].push_back ({u, w});
		}

		dfs (r, r, 0);

		while (q--) {
			int u, v;
			cin >> u >> v;
			int l = lca (u, v);

			int ans = sum[u] + sum[v] - 2 * sum[l];
			print (ans);
		}
	}
	return 0;
}