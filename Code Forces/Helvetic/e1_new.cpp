/*
				C++
				encoding: UTF-8
				Modified: <07/Jul/2019 03:42:09 PM>

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
#define         pii                    pair<ll, ll>
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

ll n, m;
const int N = 1e5 + 5;
ve< pair< ll, pii > > edges;
ll Parent[N], Rank[N], deg[N];
ll cost1, cost2;
ve< ll > graph[N];
ll vis[N];

void init () {
	fr (i, 1, n + 1) {
		Parent[i] = i;
		Rank[i] = 0;
	}
}

ll Find (ll x) {
	if (Parent[x] != x) Parent[x] = Find (Parent[x]);
	return Parent[x];
}

void Union (ll x, ll y) {
	ll x_id = Find (x);
	ll y_id = Find (y);
	if (x_id == y_id) return;
	if (Rank[x_id] > Rank[y_id])
		Parent[y_id] = x_id;
	else {
		Parent[x_id] = y_id;
		if (Rank[x_id] == Rank[y_id]) Rank[y_id]++;
	}
}

void dfs (ll node) {
	vis[node] = 1;
	for (ll to : graph[node]) {
		if (vis[to]) continue;
		dfs (to);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	init ();
	ll F, a, b;
	fr (i, 0, m) {
		ll u, v, w;
		cin >> u >> v >> w;
		deg[u]++;
		deg[v]++;
		if (i == 0) {
			F = w;
			a = u;
			b = v;
		} else {
			edges.pb ({w, {u, v}});
			graph[u].pb (v);
			graph[v].pb (u);
		}
	}
	ll ans = 1e9;
	if (deg[a] == 1 or deg[b] == 1) {
		pr1 (ans);
		return 0;
	}
	dfs (1);
	fr (i, 1, n + 1) {
		if (!vis[i]) {
			pr1 (ans);
			return 0;
		}
	}

	sort (all (edges));
	for (auto edge : edges) {
		ll weight = edge.ff;
		ll u = edge.ss.ff;
		ll v = edge.ss.ss;
		if (Find (u) != Find (v)) {
			cost1 += weight;
			Union (u, v);
		}
	}
	init ();
	Union (a, b);
	cost2 += F;
	for (auto edge : edges) {
		ll weight = edge.ff;
		ll u = edge.ss.ff;
		ll v = edge.ss.ss;
		if (Find (u) != Find (v)) {
			cost2 += weight;
			Union (u, v);
		}
	}
	pr1 (min (ans, F - cost2 + cost1));
	// pr2 (cost2, cost1);
	return 0;
}

/*
5 6
1 2 1
2 4 200
1 4 200
4 5 200
3 5 200
2 3 200
*/
