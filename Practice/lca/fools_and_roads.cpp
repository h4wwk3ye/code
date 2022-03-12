/*
				C++
				encoding: UTF-8
				Modified: <09/Oct/2019 01:42:35 PM>

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
ve< int > graph[N];
int dp[N][20];
map< pii, int > edges;
int pre[N], post[N], t;
int cnt[N], ans[N];
int n, k;

void dfs (int node, int parent) {
	pre[node] = ++t;
	dp[node][0] = parent;
	fr (i, 1, 20) {
		dp[node][i] = dp[dp[node][i - 1]][i - 1];
	}
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
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

int dfs1 (int node, int parent) {
	int curr = 0;
	for (int to : graph[node]) {
		if (to == parent) continue;
		int x = dfs1 (to, node);
		ans[edges[{node, to}]] += x;
		curr += x;
	}
	return curr + cnt[node];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		edges[{u, v}] = i;
		edges[{v, u}] = i;
	}
	dfs (1, 1);
	cin >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		int l = lca (u, v);
		cnt[l] -= 2;
		cnt[u]++;
		cnt[v]++;
	}
	dfs1 (1, 1);
	fr (i, 1, n) {
		cout << ans[i] << " ";
	}
	return 0;
}
