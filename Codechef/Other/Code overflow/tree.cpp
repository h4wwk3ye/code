//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 02/Feb/20 02:45:19 PM
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
int n, q;
int arr[N], val[N];
ve< int > graph[N];

int dfs (int node, int parent) {
	val[node] += arr[node];
	int v = 0;
	for (int& to : graph[node]) {
		if (to == parent) continue;
		v += dfs (to, node);
	}
	val[node] += v;
	return val[node];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);
	ve< pii > x;
	fr (i, 1, n + 1) {
		x.pb ({val[i], i});
	}
	sort (all (x));
	while (q--) {
		int y;
		cin >> y;
		auto it = lower_bound (all (x), y, [](pii a, int b) -> bool { return a.ff < b; });
		if (it == x.end ())
			pr (-1);
		else {
			pr (it->ss);
		}
	}
	return 0;
}