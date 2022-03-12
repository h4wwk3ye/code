/*
				C++
				encoding: UTF-8
				Last Modified: 25/Sep/20 08:57:42 PM
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
int n, m;
array< vector< int >, N > graph;
array< bool, N > vis;
int ans, l, r;

int dfs (int node, int parent) {
	vis[node] = 1;
	int s = 1;
	for (auto& to : graph[node]) {
		if (to == parent) continue;
		int c = dfs (to, node);
		if (c * (n - c) >= ans) {
			ans = c * (n - c);
			l = node;
			r = to;
		}
		s += c;
	}
	return s;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> n >> m;
	for (size_t i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back (v);
		graph[v].push_back (u);
	}
	dfs (1, 1);
	print (l, r);
	return 0;
}