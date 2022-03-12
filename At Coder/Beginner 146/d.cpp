//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Nov/19 06:03:25 PM
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
int deg[N];
int n, ans;
map< pii, pii > edges;

void dfs (int node, int parent, int c) {
	for (int to : graph[node]) {
		if (to == parent) continue;

		edges[{min (node, to), max (node, to)}].ss = ++c;
		c %= ans;
		dfs (to, node, c);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		deg[u]++;
		deg[v]++;
		ans = max (ans, max (deg[u], deg[v]));
		if (u > v) swap (u, v);
		edges[{u, v}] = {i, -1};
	}
	dfs (1, 1, 0);
	ve< int > color (len (edges));
	for (auto& i : edges) {
		color[i.ss.ff] = i.ss.ss;
	}
	pr (ans);
	for (auto& i : color)
		pr (i);
	return 0;
}