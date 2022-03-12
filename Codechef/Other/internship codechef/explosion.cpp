/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/20 08:00:52 PM
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

const int N = 1e5 + 5;
array< vector< int >, N > adj;
array< int, N > dist;
int n, ans, leaf;

void init () {
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear ();
		dist[i] = 0;
	}
}

void dfs (int node, int parent) {
	for (auto& to : adj[node]) {
		if (to == parent) continue;
		dist[to] = 1 + dist[node];
		if (dist[to] > ans) {
			ans = dist[to];
			leaf = to;
		}
		dfs (to, node);
	}
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back (v);
			adj[v].push_back (u);
		}
		// choose the root and leaf with maximum distance so ans will be at least ceil of half of the max distance
		dfs (1, 1);
		for (int i = 1; i <= n; ++i) {
			dist[i] = 0;
		}
		dfs (leaf, leaf);
		print (ceil (ans / (2 * 1.0)));
	}
	return 0;
}