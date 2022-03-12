/*
				C++
				encoding: UTF-8
				Modified: <07/Jul/2019 02:56:52 PM>

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

// Taken from cp-algorithms.com

struct edge {
	ll s, e, w, id;
	bool operator< (const struct edge& other) {
		return w < other.w;
	}
};
typedef struct edge Edge;

const ll N = 1e5 + 5;
long long res = 0, ans = 1e18;
ll n, m, a, b, w, id, l = 21;
vector< Edge > edges;
vector< ll > h (N, 0), parent (N, -1), Size (N, 0), present (N, 0);
vector< vector< pair< ll, ll > > > adj (N), dp (N, vector< pair< ll, ll > > (l));
vector< vector< ll > > up (N, vector< ll > (l, -1));

pair< ll, ll > combine (pair< ll, ll > a, pair< ll, ll > b) {
	vector< ll > v = {a.first, a.second, b.first, b.second};
	ll topTwo = -3, topOne = -2;
	for (ll c : v) {
		if (c > topOne) {
			topTwo = topOne;
			topOne = c;
		} else if (c > topTwo && c < topOne) {
			topTwo = c;
		}
	}
	return {topOne, topTwo};
}

void dfs (ll u, ll par, ll d) {
	h[u] = 1 + h[par];
	up[u][0] = par;
	dp[u][0] = {d, -1};
	for (auto v : adj[u]) {
		if (v.first != par) {
			dfs (v.first, u, v.second);
		}
	}
}

pair< ll, ll > lca (ll u, ll v) {
	pair< ll, ll > ans = {-2, -3};
	if (h[u] < h[v]) {
		swap (u, v);
	}
	for (ll i = l - 1; i >= 0; i--) {
		if (h[u] - h[v] >= (1 << i)) {
			ans = combine (ans, dp[u][i]);
			u = up[u][i];
		}
	}
	if (u == v) {
		return ans;
	}
	for (ll i = l - 1; i >= 0; i--) {
		if (up[u][i] != -1 && up[v][i] != -1 && up[u][i] != up[v][i]) {
			ans = combine (ans, combine (dp[u][i], dp[v][i]));
			u = up[u][i];
			v = up[v][i];
		}
	}
	ans = combine (ans, combine (dp[u][0], dp[v][0]));
	return ans;
}


ll Find (int x) {
	if (parent[x] != x) parent[x] = Find (parent[x]);
	return parent[x];
}

void Union (int x, int y) {
	int x_id = Find (x);
	int y_id = Find (y);
	if (x_id == y_id) return;
	if (Size[x_id] > Size[y_id])
		parent[y_id] = x_id;
	else {
		parent[x_id] = y_id;
		if (Size[x_id] == Size[y_id]) Size[y_id]++;
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0), cout.tie (0);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		parent[i] = i;
		Size[i] = 1;
	}
	ll F;
	for (ll i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		if (i == 1) F = w;
		edges.push_back ({a, b, w, i - 1});
	}
	sort (edges.begin (), edges.end ());
	for (ll i = 0; i <= m - 1; i++) {
		a = edges[i].s;
		b = edges[i].e;
		w = edges[i].w;
		id = edges[i].id;
		if (Find (a) != Find (b)) {
			adj[a].emplace_back (b, w);
			adj[b].emplace_back (a, w);
			present[id] = 1;
			res += w;
			Union (a, b);
		}
	}
	dfs (1, 0, 0);
	for (ll i = 1; i <= l - 1; i++) {
		for (ll j = 1; j <= n; ++j) {
			if (up[j][i - 1] != -1) {
				ll v = up[j][i - 1];
				up[j][i] = up[v][i - 1];
				dp[j][i] = combine (dp[j][i - 1], dp[v][i - 1]);
			}
		}
	}
	for (ll i = 0; i <= m - 1; i++) {
		id = edges[i].id;
		w = edges[i].w;
		if (!present[id]) {
			auto rem = lca (edges[i].s, edges[i].e);
			if (rem.first != w) {
				if (ans > res + w - rem.first) {
					ans = res + w - rem.first;
				}
			} else if (rem.second != -1) {
				if (ans > res + w - rem.second) {
					ans = res + w - rem.second;
				}
			}
		}
	}
	pr2 (ans, res);
	pr1 (F - (ans - res));
	return 0;
}
