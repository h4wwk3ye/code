//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/20 04:55:37 PM
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

int n;
const int N = 1e5 + 5;
ve< pii > graph[N];
ve< int > sum (N);
int mx = 0;

void dfs (int node, int parent, int curr) {
	sum[node] = curr;
	for (auto& to : graph[node]) {
		if (to.ff == parent) continue;
		dfs (to.ff, node, curr + to.ss);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	int ans = 0;

	fr (i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb ({v, w});
		graph[v].pb ({u, w});
		ans += 2 * w;
	}
	dfs (1, 1, 0);
	int mx = *max_element (all (sum));
	pr (ans - mx);

	return 0;
}