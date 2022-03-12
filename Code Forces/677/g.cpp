/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 09:55:45 PM
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

const int N = 1e3 + 5;
int arr[N];
vector< pair< int, int > > v[N];
int n, m, k;
int dist[N];
bool vis[N];

void dijkstra () {
	memset (dist, 1e9, sizeof dist);
	memset (vis, false, sizeof vis);
	dist[1] = 0;
	multiset< pair< int, int > > s;

	s.insert ({0, 1});

	while (!s.empty ()) {
		pair< int, int > p = *s.begin ();
		s.erase (s.begin ());

		int x = p.second;
		int wei = p.first;
		if (vis[x]) continue;
		vis[x] = true;

		for (int i = 0; i < v[x].size (); i++) {
			int e = v[x][i].first;
			int w = v[x][i].second;
			if (dist[x] + w < dist[e]) {
				dist[e] = dist[x] + w;
				s.insert ({dist[e], e});
			}
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		int u, V, w;
		cin >> u >> V >> w;
		v[u].push_back ({V, w});
		v[V].push_back ({u, w});
	}
	return 0;
}