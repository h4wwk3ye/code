/*
				C++
				encoding: UTF-8
				Modified: <06/Sep/2019 12:26:53 AM>

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
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

int n, m;
const int N = 5e3 + 5;
int vis[N], ans[N], color[N];
ve< pii > graph[N];
int k;

void dfs (int node) {
	vis[node] = 1;
	color[node] = 1;
	for (auto [to, idx] : graph[node]) {
		if (!vis[to])
			dfs (to);
		else if (color[to]) {
			ans[idx] = 2;
			k = 2;
		}
	}
	color[node] = 0;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 0, m) {
		int u, v;
		cin >> u >> v;
		graph[u].pb ({v, i});
	}
	fill (ans, ans + m + 1, 1);
	k = 1;
	fr (i, 1, n + 1) if (!vis[i]) dfs (i);

	pr (k);
	fr (i, 0, m) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
