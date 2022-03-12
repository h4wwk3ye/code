#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 30/Oct/19 07:16:50 PM
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
int depth[N], day[N];
int n;

void dfs (int node, int parent) {
	depth[node] = 1 + depth[parent];
	day[depth[node]]++;
	for (int to : graph[node]) {
		if (to != parent) dfs (to, node);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);
	int ans = 1, mx = 0;
	fr (i, 1, n + 1) {
		if (day[i] > mx) {
			mx = day[i];
			ans = i;
		}
	}
	pr (ans);
	return 0;
}