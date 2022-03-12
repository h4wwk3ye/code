//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 01/Mar/20 06:04:53 PM
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
int n, m, k;
int cnt[N], deg[N], vis[N], com[N];
int c;

void dfs (int node) {
	if (vis[node]) return;
	com[node] = c;
	vis[node] = 1;
	for (auto& to : graph[node]) {
		if (!vis[to]) dfs (to);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> k;
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		deg[u]++;
		deg[v]++;
	}

	fr (i, 1, n + 1) {
		if (!vis[i]) {
			++c;
			dfs (i);
		}
	}

	fr (i, 0, k) {
		int u, v;
		cin >> u >> v;
		if (com[u] != com[v]) continue;
		cnt[u]++;
		cnt[v]++;
	}


	map< int, int > mp;
	fr (i, 1, n + 1) mp[com[i]]++;

	fr (i, 1, n + 1) {
		int ans = mp[com[i]] - deg[i] - cnt[i] - 1;
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}