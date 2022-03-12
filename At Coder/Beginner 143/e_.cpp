/*
				C++
				encoding: UTF-8
				Last Modified: 19/Oct/2019 07:37:50 PM

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
int vis[N];
int dist[N][N], previous[N][N];
int s, t;

void init () {
	fr (i, 0, N) {
		vis[i] = 0;
		fr (j, 0, N) {
			dist[i][j] = 1e18;
			previous[i][j] = -1;
			if (i == j) {
				dist[i][j] = 0;
				previous[i][j] = i;
			}
		}
	}
}

void floyd () {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] < 1e18 and dist[k][j] < 1e18)
					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
						previous[i][j] = previous[i][k];
					}
			}
		}
	}
}

int path (int u, int v) {
	if (previous[u][v] == -1) {
		return -1;
	}
	int ans = 0;
	int rem = l;
	while (u != v) {
		int p = previous[u][v];
		if (dist[u][p] > l) {
			return -1;
		}
		if (rem >= dist[u][p]) {
			rem -= dist[u][p];
			u = p;

		} else {
			rem = l - dist[u][p];
			ans++;
			u = p;
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m >> l;
	init ();
	fr (i, 0, m) {
		int u, v, c;
		cin >> u >> v >> c;
		if (c > l) continue;
		dist[u][v] = c;
		dist[v][u] = c;

		previous[u][v] = v;
		previous[v][u] = u;
	}

	floyd ();

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s >> t;
		if (dist[s][t] == 1e18) {
			pr (-1);
			continue;
		}
		int ans = path (s, t);
		pr (ans);
	}
	return 0;
}
