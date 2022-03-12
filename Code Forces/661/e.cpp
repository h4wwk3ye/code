/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 09:06:34 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

const int N = 1e5 + 5;
vector< pair< int, int > > graph[N];
int n, s;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto init = [&] () {
		for (int i = 0; i < n + 2; ++i) {
			graph[i].clear ();
		}
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> s;
		init ();

		for (int i = 1; i < n; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			graph[u].push_back ({v, w});
			graph[v].push_back ({u, w});
		}
	}
	return 0;
}