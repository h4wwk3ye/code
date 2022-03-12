//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Jan/20 10:27:23 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		char arr[n][m];
		int dist[n][m];
		int vis[n][m];
		pii source;
		fr (i, 0, n) fr (j, 0, m) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {
				source.ff = i;
				source.ss = j;
				dist[i][j] = 0;
			} else
				dist[i][j] = 1e9;

			vis[i][j] = 0;
		}
		queue< pii > q;

		auto neighbours = [&](pii x) -> vector< pii > {
			vector< pii > ans = {{x.ff - 1, x.ss}, {x.ff + 1, x.ss}, {x.ff, x.ss - 1}, {x.ff, x.ss + 1}};
			return ans;
		};

		auto check = [&](pii x) -> bool { return x.ff >= 0 and x.ff < n and x.ss >= 0 and x.ss < m; };

		q.push (source);
		vis[source.ff][source.ss] = 1;
		while (!q.empty ()) {
			pii node = q.front ();
			q.pop ();
			for (auto& p : neighbours (node)) {
				if (check (p) and arr[p.ff][p.ss] != 'x' and !vis[p.ff][p.ss]) {
					vis[p.ff][p.ss] = 1;
					dist[p.ff][p.ss] = 1 + dist[node.ff][node.ss];
					q.push (p);
				}
			}
		}
		fr (i, 0, n) {
			fr (j, 0, m) {
				if (arr[i][j] == 'D') {
					pr (dist[i][j]);
					break;
				}
			}
		}
	}
	return 0;
}