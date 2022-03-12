/*
				C++
				encoding: UTF-8
				Modified: <07/Oct/2019 10:02:14 PM>

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

#define         ll                     long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n"
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 1e3 + 5;
ve< int > graph[N];
int n, lg;
int lvl[N], dp[N][20];

void dfs (int node, int parent) {
	lvl[node] = 1 + lvl[parent];
	dp[node][0] = parent;
	fr (i, 1, lg + 1) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
	}
}

int lca (int u, int v) {
	if (lvl[u] < lvl[v]) swap (u, v);

	for (int i = lg; i >= 0; i--) {
		if (lvl[u] >= lvl[v] + (1 << i)) {
			u = dp[u][i];
		}
	}
	if (u == v) return u;

	for (int i = lg; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) {
			u = dp[u][i];
			v = dp[v][i];
		}
	}
	return dp[u][0];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	auto init = [&]() -> void {
		fr (i, 0, n + 2) {
			graph[i].clear ();
			lvl[i] = 0;
			fr (j, 0, lg + 2) dp[i][j] = 0;
		}
	};

	fr (TC, 1, tc + 1) {
		cout << "Case"
			 << " " << TC << ":\n";
		cin >> n;
		lg = log2 (n) + 1;
		init ();
		fr (i, 1, n + 1) {
			int m;
			cin >> m;
			fr (j, 1, m + 1) {
				int v;
				cin >> v;
				graph[i].pb (v);
				graph[v].pb (i);
			}
		}
		dfs (1, 1);
		int q;
		cin >> q;
		while (q--) {
			int u, v;
			cin >> u >> v;
			pr (lca (u, v));
		}
	}

	return 0;
}
