/*
				C++
				encoding: UTF-8
				Modified: <08/Oct/2019 10:39:48 PM>

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

const int N = 1e5 + 5;
ve< pii > graph[N];
int n, q;
int dp[N][20], lvl[N];
int pre[N], post[N], t;
int mx[N][20], mn[N][20];

void dfs (int node, int parent, int weight) {
	pre[node] = ++t;
	dp[node][0] = parent;
	mx[node][0] = mn[node][0] = weight;
	lvl[node] = 1 + lvl[parent];
	fr (i, 1, 20) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (auto& to : graph[node]) {
		if (to.ff == parent) continue;
		dfs (to.ff, node, to.ss);
	}
	post[node] = ++t;
}

bool is_ancestor (int u, int v) {
	return pre[u] <= pre[v] and post[v] <= post[u];
}

int lca (int u, int v) {
	if (is_ancestor (u, v)) return u;
	if (is_ancestor (v, u)) return v;
	dfr (i, 19, -1) {
		if (!is_ancestor (dp[u][i], v)) {
			u = dp[u][i];
		}
	}
	return dp[u][0];
}

ve< int > cal (int u, int v) {
	ve< int > ans = {-1, (int)1e9};
	dfr (i, 19, -1) {
		if (lvl[v] - (1 << i) >= lvl[u]) {
			ans[0] = max (ans[0], mx[v][i]);
			ans[1] = min (ans[1], mn[v][i]);
			v = dp[v][i];
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].pb ({v, w});
		graph[v].pb ({u, w});
	}
	lvl[1] = -1;
	dfs (1, 1, -1);

	fr (j, 1, 20) {
		fr (i, 1, n + 1) {
			mx[i][j] = max (mx[i][j - 1], mx[dp[i][j - 1]][j - 1]);
			mn[i][j] = min (mn[i][j - 1], mn[dp[i][j - 1]][j - 1]);
		}
	}
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		int l = lca (u, v);
		if (l == u) {
			ve< int > ans = cal (u, v);
			pr (ans[1], ans[0]);
		} else if (l == v) {
			ve< int > ans = cal (v, u);
			pr (ans[1], ans[0]);
		} else {
			ve< int > a = cal (l, u);
			ve< int > b = cal (l, v);
			pr (min (a[1], b[1]), max (a[0], b[0]));
		}
	}

	return 0;
}
