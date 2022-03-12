//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 10/Nov/19 10:57:07 PM
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
int arr[N], val[N];
ve< int > graph[N];
int n, k, x;

int dfs (int node, int parent) {
	int c = arr[node];
	for (int to : graph[node]) {
		if (to != parent) c += dfs (to, node);
	}
	val[node] = c;
	return c;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	auto init = [&] () { fr (i, 0, n + 1) graph[i].clear (); };
	while (tc--) {
		cin >> n >> k >> x;
		init ();
		fr (i, 1, n + 1) cin >> arr[i];
		fr (i, 1, n) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		dfs (1, 1);
		sort (val + 1, val + n + 1);
		int ans = 0;
		fr (i, 1, k + 1) ans += val[i];
		pr (max (0LL, x - ans));
	}

	return 0;
}