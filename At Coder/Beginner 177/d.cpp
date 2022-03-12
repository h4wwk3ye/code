/*
				C++
				encoding: UTF-8
				Last Modified: 29/Aug/20 05:54:43 PM
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
	cout << t << " ";
	print (u, args...);
}

int n, m;
const int N = 2e5 + 5;
vector< int > graph[N];
int vis[N];

int dfs (int node) {
	vis[node] = 1;
	int ans = 1;
	for (auto& to : graph[node]) {
		if (!vis[to]) {
			ans += dfs (to);
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	set< pair< int, int > > edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap (u, v);
		if (edges.find ({u, v}) == edges.end ()) {
			graph[u].push_back (v);
			graph[v].push_back (u);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vis[i]) {
			ans = max (ans, dfs (i));
		}
	}
	print (ans);
	return 0;
}