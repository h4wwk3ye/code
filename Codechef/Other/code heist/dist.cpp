//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Jan/20 10:20:39 PM
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
int n, m, k, a, b;
int vis[N], dist[N];
ve< pii > graph[N];

void dijkstra (int src) {
	dist[src] = 0;
	multiset< pii > s;

	s.insert ({src, 0});

	while (!s.empty ()) {
		pii p = *s.begin ();
		s.erase (s.begin ());

		int node = p.ff;
		int w = p.ss;
		if (vis[node]) continue;
		vis[node] = 1;

		for (auto& to : graph[node]) {
			if (dist[node] + to.ss < dist[to.ff]) {
				dist[to.ff] = dist[node] + to.ss;
				s.insert ({to.ff, dist[to.ff]});
			}
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto init = [&]() {
		fr (i, 0, n + 5) {
			vis[i] = 0;
			graph[i].clear ();
		}
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k >> a >> b;
		init ();

		fr (i, 0, m) {
			int u, v, c;
			cin >> u >> v >> c;
			graph[u].pb ({v, c});
		}

		int ans = 1e18;

		fr (i, 0, k) {
			int u, v, c;
			cin >> u >> v >> c;
			graph[u].pb ({v, c});
			graph[v].pb ({u, c});
			fr (j, 1, n + 1) {
				dist[j] = 1e18;
				vis[j] = 0;
			}
			dijkstra (a);
			ans = min (ans, dist[b]);
			graph[u].pop_back ();
			graph[v].pop_back ();
		}
		if (ans == 1e18) ans = -1;
		pr (ans);
	}
	return 0;
}