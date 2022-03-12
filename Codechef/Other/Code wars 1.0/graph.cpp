//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jan/20 08:55:00 PM
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

const int N = 1e6 + 5;
ve< pii > graph[N];
int dist[N], vis[N];
int n, m, h;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> h;
	fr (i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb ({v, w});
		graph[v].pb ({u, w});
	}

	auto dijkstra = [&](int src) {
		reset (dist, 1e9);
		dist[src] = 0;
		multiset< pii > s;
		s.insert ({0, src});

		while (!s.empty ()) {
			auto p = *s.begin ();
			s.erase (s.begin ());

			if (vis[p.ss]) continue;
			vis[p.ss] = 1;

			for (auto& x : graph[p.ss]) {
				if (dist[x.ff] > x.ss + dist[p.ss]) {
					dist[x.ff] = dist[p.ss] + x.ss;
					s.insert ({dist[x.ff], x.ff});
				}
			}
		}
	};

	dijkstra (h);
	int ans = 1e10;
	int src = 1;
	fr (i, 1, m + 1) {
		int x;
		cin >> x;
		if (dist[x] < ans) {
			ans = dist[x];
			src = x;
		}
	}
	pr (src);
	return 0;
}