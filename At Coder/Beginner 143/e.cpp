/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/2019 12:19:00 AM

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

#define		 int                    long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n"
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 (int)v.size()
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 305;
int n, m, l;
int dist[N][N], c[N][N];
int s, t;

void init () {
	fr (i, 0, N) {
		fr (j, 0, N) {
			dist[i][j] = 1e18;
			if (i == j) {
				dist[i][j] = 0;
			}
		}
	}
}

void floyd () {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	fr (i, 1, n + 1) {
		fr (j, 1, n + 1) {
			c[i][j] = (dist[i][j] <= l ? 1 : 1e18);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				c[i][j] = min (c[i][j], c[i][k] + c[k][j]);
			}
		}
	}
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int _;
	cin >> _;
	while (_--) {
		cin >> n >> m >> l;
		init ();
		fr (i, 0, m) {
			int u, v, c;
			cin >> u >> v >> c;
			dist[u][v] = c;
			dist[v][u] = c;
		}

		floyd ();

		int tc;
		cin >> tc;
		while (tc--) {
			cin >> s >> t;
			pr (c[s][t] < 1e18 ? c[s][t] - 1 : -1);
		}
	}

	return 0;
}
