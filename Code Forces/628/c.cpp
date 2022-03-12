//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Mar/20 11:26:02 PM
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
int n;
map< pii, int > edges;
int c = 0;
int ans[N], deg[N], vis[N];

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	int root = 1;
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap (u, v);
		graph[u].pb (v);
		graph[v].pb (u);
		edges[{u, v}] = i;
		ans[i] = -1;
		deg[u]++;
		deg[v]++;
		if (deg[u] >= deg[root]) root = u;
		if (deg[v] >= deg[root]) root = v;
	}

	if (root == 1 and deg[1] <= 2) {
		fr (i, 0, n - 1) pr (i);
		return 0;
	}

	queue< int > q;
	q.push (root);
	vis[root] = 1;
	while (!q.empty ()) {
		auto node = q.front ();
		q.pop ();
		for (auto& to : graph[node]) {
			if (vis[to]) continue;
			vis[to] = 1;
			int u = min ({node, to});
			int v = max ({node, to});
			ans[edges[{u, v}]] = c++;
			q.push (to);
		}
	}
	fr (i, 1, n) pr (ans[i]);

	return 0;
}