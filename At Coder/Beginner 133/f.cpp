/*
				C++
				encoding: UTF-8
				Modified: <07/Jul/2019 07:09:37 PM>

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

const ll N = 1e5 + 5;
ve< ll > adj[N];
ll n, qu;
ll parent[N], depth[N], heavy[N], head[N], chain[N], size[N];
ll ans;
map< pii, pii > s;

void init () {
	fr (i, 0, N) {
		heavy[i] = -1;
	}
}

void DFS (ll i) {
	size[i] = 1;
	for (ll j : adj[i]) {
		if (j == parent[i]) continue;
		parent[j] = i;
		depth[j] = depth[i] + 1;

		DFS (j);

		size[i] += size[j];
		if (heavy[i] == -1 || size[j] > size[heavy[i]]) heavy[i] = j;
	}
}

void heavylight_DFS () {
	parent[0] = -1;
	depth[0] = 0;
	DFS (0);

	ll c = 0;
	for (ll i = 0; i < n; ++i)
		if (parent[i] == -1 || heavy[parent[i]] != i) {
			for (ll k = i; k != -1; k = heavy[k])
				chain[k] = c, head[k] = i;
			c++;
		}
}

ll lca (ll i, ll j) {
	while (chain[i] != chain[j]) {
		if (depth[head[i]] > depth[head[j]])
			i = parent[head[i]];
		else
			j = parent[head[j]];
	}

	return depth[i] < depth[j] ? i : j;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> qu;
	init ();
	fr (i, 1, n) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		b--;
		adj[a].pb (b);
		adj[b].pb (a);
		s[{a, b}] = {c, d};
		s[{b, a}] = {c, d};
	}
	heavylight_DFS ();
	while (qu--) {
		ll x, y, u, v;
		cin >> x >> y >> u >> v;
		u--;
		v--;
		ll l = lca (u, v);
		ll tmp = u, tmp1;
		ll ans = 0;
	}
	return 0;
}
