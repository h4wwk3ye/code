//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Mar/20 09:54:10 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	fr (i, 0, n) fr (j, 0, m) cin >> arr[i][j];
	ve< ve< int > > vis, dis;
	ve< ve< int > > ans (n, ve< int > (m, 0));

	auto manhattan = [](int x1, int y1, int x2, int y2) { return abs (x1 - x2) + abs (y1 - y2); };

	auto neighbors = [](pii x) -> ve< pii > {
		return {{x.ff - 1, x.ss}, {x.ff + 1, x.ss}, {x.ff, x.ss - 1}, {x.ff, x.ss + 1}};
	};

	auto check = [&](pii x) -> bool { return x.ff >= 0 and x.ff < n and x.ss >= 0 and x.ss < m; };

	fr (i, 0, n) {
		fr (j, 0, m) {
			if (!arr[i][j]) {
				vis.assign (n, ve< int > (m, 0));
				dis.assign (n, ve< int > (m, 1e9));
				dis[i][j] = 0;
				queue< pii > q;
				q.push ({i, j});
				int mn = 1e9;
				vis[i][j] = 1;
				while (!q.empty ()) {
					auto node = q.front ();
					q.pop ();
					for (auto& p : neighbors (node)) {
						if (check (p) and !vis[p.ff][p.ss]) {
							dis[p.ff][p.ss] = 1 + dis[node.ff][node.ss];
							if (arr[p.ff][p.ss]) mn = min (mn, dis[p.ff][p.ss]);
							q.push (p);
							vis[p.ff][p.ss] = 1;
						}
					}
				}
				ans[i][j] = mn;
			}
		}
	}
	fr (i, 0, n) {
		fr (j, 0, m) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}