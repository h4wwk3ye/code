/*
				C++
				encoding: UTF-8
				Modified: <18/Sep/2019 11:31:45 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>
#ifdef LOCAL_PROJECT
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

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
int n, m;
int arr[N];
ve< int > graph[N];
set< pii > edges;
int vis[N];
set< pii > e;

int dfs (int node) {
	int ans = arr[node];
	int curr = 0;
	for (int to : graph[node]) {
		if (vis[to]) continue;
		pii edge = {to, node};
		if (e.find (edge) != e.end ()) continue;
		e.insert ({node, to});
		e.insert ({to, node});
		curr = max (curr, dfs (to));
	}
	return ans + curr;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	int u, v;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 0, m) {
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		edges.insert ({u, v});
		edges.insert ({v, u});
	}
	int s;
	cin >> s;
	int ans = dfs (s);
	pr (ans);

	return 0;
}
