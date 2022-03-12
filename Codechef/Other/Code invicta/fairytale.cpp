//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 25/Mar/20 10:31:06 PM
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

// cp-algorithms.com

int n, m;					 // number of nodes
vector< vector< int > > adj; // adjacency list of graph

vector< bool > visited;
vector< int > tin, low;
int timer;
map< pii, int > edges;
set< int > animal;
int ans;

void IS_BRIDGE (int v, int to) {
	if (v > to) swap (v, to);
	if (animal.find (edges[{v, to}]) != animal.end ()) ans++;
}

void dfs (int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min (low[v], tin[to]);
		} else {
			dfs (to, v);
			low[v] = min (low[v], low[to]);
			if (low[to] > tin[v]) {
				IS_BRIDGE (v, to);
			}
		}
	}
}

void find_bridges () {
	timer = 0;
	visited.assign (n, false);
	tin.assign (n, -1);
	low.assign (n, -1);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) dfs (i);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	adj.resize (n);
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].pb (v);
		adj[v].pb (u);
		if (u > v) swap (u, v);
		edges[{u, v}] = i + 1;
	}
	int x;
	cin >> x;
	fr (i, 0, x) {
		int y;
		cin >> y;
		animal.insert (y);
	}
	find_bridges ();
	pr (ans);
	return 0;
}