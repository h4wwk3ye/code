/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/20 07:10:48 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

const int N = 1e5 + 5;

array< vector< int >, N > adj;
array< int, N > dist;

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, k;
		cin >> n >> m >> k;
		auto init = [&] () {
			for (int i = 1; i <= n; ++i) {
				adj[i].clear ();
				dist[i] = 1e9;
			}
		};

		init ();
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back (v);
			adj[v].push_back (u);
		}

		queue< int > q;
		for (int i = 0; i < k; ++i) {
			int x;
			cin >> x;
			q.push (x);
			dist[x] = 0;
		}

		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();
			for (auto& to : adj[node]) {
				if (dist[to] > dist[node] + 1) {
					dist[to] = dist[node] + 1;
					q.push (to);
				}
			}
		}
		int t;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			print (dist[x] == 1e9 ? -1 : dist[x]);
		}
	}
	return 0;
}