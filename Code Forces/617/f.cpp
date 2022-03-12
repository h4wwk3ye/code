#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 06/Feb/20 11:04:46 PM
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
int n, m;
ve< int > graph[N];
ve< pii > tree[N];

int dp[N][14];
map< pii, pii > edges;
int pre[N], post[N], t;

int par[N];
int st[N][N];

void dfs (int node, int parent) {
	pre[node] = ++t;
	dp[node][0] = parent;
	par[node] = parent;
	fr (i, 1, 14) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (int& to : graph[node]) {
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
	dfr (i, 13, -1) {
		if (!is_ancestor (dp[u][i], v)) {
			u = dp[u][i];
		}
	}
	return dp[u][0];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		if (u > v) swap (u, v);
		edges[{u, v}] = {i, 1e6};
	}
	dfs (n, n);

	cin >> m;

	ve< tuple< int, int, int > > queries (m);

	fr (i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v) swap (u, v);

		queries[i] = {u, v, w};

		int l = lca (u, v);
		st[u][v] = l;

		while (u != l) {
			int p = par[u];
			int x = min (u, p), y = max (u, p);
			if (edges[{x, y}].ss == 1e6)
				edges[{x, y}].ss = w;
			else
				edges[{x, y}].ss = max (edges[{x, y}].ss, w);
			u = p;
		}
		while (v != l) {
			int p = par[v];
			int x = min (v, p), y = max (v, p);
			if (edges[{x, y}].ss == 1e6)
				edges[{x, y}].ss = w;
			else
				edges[{x, y}].ss = max (edges[{x, y}].ss, w);
			v = p;
		}
	}

	bool flag = 0;

	for (auto& [u, v, w] : queries) {
		int l = st[u][v];
		int mn = 1e6;
		while (u != l) {
			int p = par[u];
			int x = min (u, p), y = max (u, p);
			mn = min (mn, edges[{x, y}].ss);
			u = p;
		}
		while (v != l) {
			int p = par[v];
			int x = min (v, p), y = max (v, p);
			edges[{x, y}].ss = max (edges[{x, y}].ss, w);
			mn = min (mn, edges[{x, y}].ss);
			v = p;
		}
		if (mn != w) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		pr (-1);
		return 0;
	}

	ve< int > e (n - 1);

	for (auto& edge : edges) {
		if (edge.ss.ss == -1) edge.ss.ss = 1;
		e[edge.ss.ff] = edge.ss.ss;
	}

	fr (i, 0, n - 1) cout << e[i] << " ";
	cout << endl;

	return 0;
}