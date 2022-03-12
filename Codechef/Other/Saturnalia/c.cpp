//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Nov/19 09:51:26 PM
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

const int N = 1e4 + 5;
ve< int > graph[N];
int vis[N];
int n, m;

void dfs (int node) {
	vis[node] = 1;
	for (int to : graph[node]) {
		if (!vis[to]) {
			dfs (to);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;

	auto init = [&] () {
		fr (i, 0, n + 2) {
			graph[i].clear ();
			vis[i] = 0;
		}
	};

	while (tc--) {
		cin >> n >> m;
		init ();
		fr (i, 0, m) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		int ans = 0;
		ve< int > mn;
		fr (i, 1, n + 1) {
			if (!vis[i]) {
				mn.pb (i);
				dfs (i);
			}
		}
		fr (i, 1, len (mn)) {
			ans += mn[i];
		}
		pr (ans);
	}
	return 0;
}