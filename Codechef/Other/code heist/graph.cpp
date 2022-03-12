//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jan/20 09:51:55 PM
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

int p;
int arr[9];
ve< int > graph[9];
int vis[9], completed[9];

int dfs (int node, int s) {
	int ans = 0;
	if (s) ans = arr[node];
	vis[node] = 1;
	for (int& to : graph[node]) {
		if (!vis[to]) {
			ans += dfs (to, 1 ^ s);
		}
	}
	return ans;
}

set< int > s;

void scc (int node) {
	vis[node] = 1;
	s.insert (node);
	for (int& to : graph[node]) {
		if (!vis[to]) scc (to);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	fr (i, 1, 9) cin >> arr[i];
	cin >> p;
	fr (i, 0, p) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}

	int ans = 0;
	fr (i, 1, 9) {
		if (completed[i]) continue;
		scc (i);
		int curr = 0;
		for (auto& node : s) {
			reset (vis, 0);
			curr = max (curr, dfs (node, 1));
			completed[node] = 1;
		}
		s.clear ();
		ans += curr;
	}
	pr (ans);
	return 0;
}