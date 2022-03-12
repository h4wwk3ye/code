#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Oct/19 11:12:09 AM
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

const int N = 1e5 + 5;
ve< int > graph[N];
int dp[N][20];
int xr[N];
int arr[N], pre[N], post[N];
int n, q;
int t;

void init () {
	fr (i, 0, n + 5) {
		fr (j, 0, 20) {
			dp[i][j] = 0;
		}
		graph[i].clear ();
		xr[i] = 0;
		pre[i] = 0;
		post[i] = 0;
	}
}

void dfs (int node, int parent) {
	pre[node] = ++t;
	dp[node][0] = parent;
	xr[node] = xr[parent] ^ arr[node];
	fr (i, 1, 20) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
	}
	post[node] = ++t;
}

bool is_ancestor (int u, int v) {
	return pre[u] <= pre[v] and post[v] <= post[u];
}

int lca (int u, int v) {
	if (is_ancestor (u, v)) return u;
	if (is_ancestor (v, u)) return v;
	dfr (i, 19, -1) {
		if (!is_ancestor (dp[u][i], v)) {
			u = dp[u][i];
		}
	}
	return dp[u][0];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		init ();
		fr (i, 1, n + 1) cin >> arr[i];
		fr (i, 1, n) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		dfs (1, 1);

		while (q--) {
			int u, v;
			cin >> u >> v;
			int l = lca (u, v);
			int ans = xr[u];
			ans ^= xr[v];
			ans ^= arr[l];
			pr (ans);
		}
	}
	return 0;
}