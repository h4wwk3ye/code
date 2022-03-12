/*
				C++
				encoding:UTF-8
				Modified: <16/Jun/2019 11:33:02 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT), Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     long long
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
//#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, ll>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (ll i = s ; i > n ; --i)

// clang-format on


/*const ll N = 600;

ll parent[N], rnk[N];
ll n, m, k;
vector< pair< ll, pair< ll, ll > > > edges;
ll ans;
vector< ll > cost;

ll Find (ll x) {
	if (parent[x] != x) parent[x] = Find (parent[x]);
	return parent[x];
}

void Union (ll x, ll y) {
	ll x_id = Find (x);
	ll y_id = Find (y);
	if (x_id == y_id) return;
	if (rnk[x_id] > rnk[y_id])
		parent[y_id] = x_id;
	else {
		parent[x_id] = y_id;
		if (rnk[x_id] == rnk[y_id]) rnk[y_id]++;
	}
}

void kruskal () {
	ll weight, u, v;
	for (auto edge : edges) {
		weight = edge.ff;
		u = edge.ss.ff;
		v = edge.ss.ss;
		if (Find (u) != Find (v)) {
			cost.pb (weight);
			ans += weight;
			Union (u, v);
		}
	}
}
*/
signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	ll n, m;
	cin >> n >> m;
	ll s[n + 1], w[m + 1];
	fr (i, 1, n + 1) cin >> s[i];
	fr (i, 1, m + 1) cin >> w[i];
	ve< ll > graph[n + 1];
	pii edges[m];
	int color[n + 1];
	fill (color, color + n + 1, -1);
	map< ll, pii > mp;
	fr (i, 0, m) {
		ll u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		edges[i] = {w[i + 1], i + 1};
		mp[i] = {u, v};
		if (color[u] != -1 and color[v] != -1) continue;
		if (color[u] == -1 and color[v] == -1) {
			color[u] = 1;
			color[v] = 0;
		} else if (color[u] != -1) {
			color[v] = 1 - color[u];
		} else if (color[v] != -1) {
			color[u] = 1 - color[u];
		}
	}
	sort (edges, edges + m, greater<> ());
	ll mx = edges[m - 1].ff;
	ll i = 0;
	ll curr = edges[i].ff;
	int f = 1;
	while (i < m and curr >= 2 * mx / 4) {
		cout << edges[i].ss << endl;
		cout << flush;
		int t;
		cin >> t;
		if (t == 1 or t == 0) {
			int p, q;
			cin >> p >> q;
		}
		pii p = mp[i];
		color[p.ff] = 1;
		color[p.ss] = 0;
		f = 1 - f;
		i++;
		curr = edges[i].ff;
	}

	cout << -1 << endl;
	cout << flush;
	// int f = 0;
	fr (i, 1, n + 1) {
		if (color[i] == 0)
			cout << "G";
		else
			cout << "C";
		// f = 1 - f;
	}
	cout << flush;
	return 0;
}
