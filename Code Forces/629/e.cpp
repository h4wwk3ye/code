//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 26/Mar/20 10:39:32 PM
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

int n, m;
const int N = 2e5 + 5, l = 20;
ve< int > graph[N];
ve< int > pre (N), post (N), parent (N);
int timer;

void dfs (int v, int p) {
	pre[v] = ++timer;
	parent[v] = p;
	for (int u : graph[v]) {
		if (u != p) dfs (u, v);
	}
	post[v] = ++timer;
}

bool is_ancestor (int u, int v) {
	return pre[u] <= pre[v] && post[u] >= post[v];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);
	while (m--) {
		int k;
		cin >> k;
		ve< int > v (k);
		fr (i, 0, k) {
			cin >> v[i];
			v[i] = parent[v[i]];
		}
		sort (all (v), [](int& a, int& b) { return pre[a] < pre[b]; });
		bool flag = 1;
		fr (i, 0, k - 1) {
			if (v[i] == v[i + 1]) continue;
			if (is_ancestor (v[i], v[i + 1]) or is_ancestor (v[i + 1], v[i])) continue;
			flag = 0;
		}
		pr (flag ? "YES" : "NO");
	}

	return 0;
}