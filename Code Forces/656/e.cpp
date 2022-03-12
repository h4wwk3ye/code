/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jul/20 10:20:01 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

const int N = 2e5 + 5;
vector< int > graph[N], adj[N];
set< int > ad[N];
int sink[N];
int n, m;

vector< char > color;
vector< int > parent;
int cycle_start, cycle_end;

vector< bool > visited;
vector< int > ans;

void dfs (int v) {
	visited[v] = true;
	for (int u : adj[v]) {
		if (!visited[u]) dfs (u);
	}
	ans.push_back (v);
}

void topological_sort () {
	visited.assign (n, false);
	ans.clear ();
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) dfs (i);
	}
	reverse (ans.begin (), ans.end ());
}

bool dfs1 (int v) {
	color[v] = 1;
	for (int u : adj[v]) {
		if (color[u] == 0) {
			parent[u] = v;
			if (dfs1 (u)) return true;
		} else if (color[u] == 1) {
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2;
	return false;
}

bool find_cycle () {
	color.assign (n + 1, 0);
	parent.assign (n + 1, -1);
	cycle_start = -1;

	for (int v = 0; v < n; v++) {
		if (color[v] == 0 && dfs1 (v)) break;
	}

	return cycle_start != -1;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;

	auto init = [&] () {
		for (int i = 0; i < n + 2; ++i) {
			graph[i].clear ();
			adj[i].clear ();
			sink[i] = 0;
			ad[i].clear ();
		}
	};

	while (tc--) {
		cin >> n >> m;
		init ();

		for (int i = 0; i < m; ++i) {
			int t, u, v;
			cin >> t >> u >> v;
			u--;
			v--;
			if (t) {
				graph[u].push_back (v);
				sink[v] = 1;
				adj[u].push_back (v);
				ad[u].insert (v);
			} else {
				graph[u].push_back (v);
				graph[v].push_back (u);
			}
		}

		if (find_cycle ()) {
			print ("No");
			continue;
		}

		topological_sort ();
		print (ans);
		for (int i = 0; i < n; ++i) {
			for (auto& j : graph[i]) {
				if (ad[i].find (j) == ad[i].end () and ad[j].find (i) == ad[j].end ()) {
					if (ans[i] <= ans[j]) {
						adj[i].push_back (j);
						ad[i].insert (j);
					} else {
						adj[j].push_back (i);
						ad[j].insert (i);
					}
				}
			}
		}

		if (find_cycle ()) {
			print ("No");
			// continue;
		}

		print ("Yes");

		for (int i = 0; i < n; ++i) {
			for (auto& j : adj[i]) {
				print (i + 1, j + 1);
			}
		}
	}
	return 0;
}