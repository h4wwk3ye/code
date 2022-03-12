//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 05/Apr/20 10:08:44 PM
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

int n, m, x;				 // number of nodes
vector< vector< int > > adj; // adjacency list of graph
set< int > infected;
vector< int > contains, length;
int ans;

vector< bool > visited;
vector< int > tin, low, pre;
int timer;

void IS_CUTPOINT (int v) {
	int curr = 0;
	for (int& to : adj[v]) {					  // one of them will be the anccestor
		if (pre[to] < pre[v]) {					  // ancestor
			if (contains[0] - contains[v] == 0) { // no infectd person on this branch
				curr += length[0] - length[v];
			} else { // not an ancestor
				if (contains[to]) }
		}
	}
}

void DFS (int v, int p) {
	pre[v] = ++timer;
	visited[v] = 1;
	length[v]++;
	if (infected.find (v) != infected.end ()) contains[v]++;
	for (int& to : adj[v]) {
		if (to == p or visited[to]) continue;
		DFS (to, v);
		contains[v] += contains[to];
		length[v] += length[to];
	}
}

void dfs (int v, int p = -1) {
	visited[v] = true;
	tin[v] = low[v] = timer++;
	int children = 0;
	for (int to : adj[v]) {
		if (to == p) continue;
		if (visited[to]) {
			low[v] = min (low[v], tin[to]);
		} else {
			dfs (to, v);
			low[v] = min (low[v], low[to]);
			if (low[to] >= tin[v] && p != -1) IS_CUTPOINT (v);
			++children;
		}
	}
	if (p == -1 && children > 1) IS_CUTPOINT (v);
}

void find_cutpoints () {
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

	auto init = [&] () {
		ans = 0;
		adj.resize (n);
		fr (i, 0, n) adj[i].clear ();
		infected.clear ();
		contains.assign (n, 0);
		length.assign (n, 0);
		visited.assign (n, false);
		pre.assign (n, 0);
		timer = 0;
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> x;
		init ();
		bool flag = 0;
		fr (i, 0, x) {
			int y;
			cin >> y;
			infected.insert (y);
			flag = 1;
		}

		fr (i, 0, m) {
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			adj[u].pb (v);
			adj[v].pb (u);
		}
		DFS (0, 0);
		find_cutpoints ();
	}
	return 0;
}