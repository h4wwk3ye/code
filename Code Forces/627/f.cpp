//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 13/Mar/20 11:15:18 AM
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

const int N = 2e5 + 5;
int arr[N];
ve< int > graph[N];
int ans[N], mx[N];
int n;

void dfs (int node, int parent) {
	if (arr[node])
		mx[node]++;
	else
		mx[node]--;

	for (int& to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
		if (mx[to] > 0) mx[node] += mx[to];
	}
}

void fix (int node, int parent) {
	ans[node] = mx[node];
	for (int& to : graph[node]) {
		if (to == parent) continue;
		mx[node] -= max (0ll, mx[to]);
		mx[to] += max (0ll, mx[node]);
		fix (to, node);
		mx[to] -= max (0ll, mx[node]);
		mx[node] += max (0ll, mx[to]);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}

	dfs (1, 1);
	fix (1, 1);
	fr (i, 1, n + 1) {
		cout << ans[i] << " ";
	}

	return 0;
}