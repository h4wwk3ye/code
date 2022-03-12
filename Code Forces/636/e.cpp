//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Apr/20 10:38:06 PM
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

int n, m, a, b, c;
ve< int > p;
const int N = 2e5 + 5;
ve< int > adj[N];


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	auto init = [&] () {
		p.clear ();
		p.resize (m);
		fr (i, 0, n + 2) adj[i].clear ();
	};

	auto bfs = [&] (int root) {
		ve< int > dis (n + 2, -1);
		dis[root] = 0;
		queue< int > q;
		q.push (root);

		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();

			for (auto& to : adj[node]) {
				if (dis[to] != -1) continue;
				q.push (to);
				dis[to] = 1 + dis[node];
			}
		}

		return dis;
	};


	while (tc--) {
		cin >> n >> m >> a >> b >> c;
		init ();

		for (auto& i : p)
			cin >> i;

		sort (all (p));
		ve< int > prefix;
		prefix.pb (0);

		for (auto& i : p) {
			prefix.pb (i + prefix.back ());
		}

		fr (i, 0, m) {
			int u, v;
			cin >> u >> v;
			adj[u].pb (v);
			adj[v].pb (u);
		}

		ve< int > dista = bfs (a);
		ve< int > distb = bfs (b);
		ve< int > distc = bfs (c);

		int ans = 1e18;

		fr (node, 1, n + 1) {
			int da = dista[node];
			int db = distb[node];
			int dc = distc[node];
			// pr (da, db, dc, prefix, dista, distb, distc);
			if (da + db + dc > m) continue;


			ans = min (ans, prefix[db] * 2 + (prefix[da + db + dc] - prefix[db]));
		}
		pr (ans);
	}
	return 0;
}