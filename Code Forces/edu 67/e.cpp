/*
				C++
				encoding: UTF-8
				Modified: <30/Jun/2019 10:39:56 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define         ll                     long long
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         umap                   unordered_map
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define         pr1(x)                 cout<<x<<"\n"
#define         pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define         pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define         prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on
int n;
const int N = 2e5 + 5;
ve< int > graph[N];
int sz[N];
ll total, ans;

void dfs (int node = 1, int parent = 1) {
	sz[node] = 1;
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
		sz[node] += sz[to];
	}
	total += sz[node];
}

void dfs1 (ll curr, int node = 1, int parent = 1) {
	ans = max (ans, curr);
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs1 (curr - sz[to] + n - sz[to], to, node);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs ();
	dfs1 (total);
	pr1 (ans);
	return 0;
}
