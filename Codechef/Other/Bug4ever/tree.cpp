/*
				C++
				encoding: UTF-8
				Modified: <05/Oct/2019 12:54:00 PM>

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

const ll N = 1e5 + 5;
ve< ll > adj[N];
ll n, q;
ll parent[N], depth[N], heavy[N], head[N], chain[N], size[N];
ll ans;

void init () {
	fr (i, 0, N) {
		adj[i].clear ();
		parent[i] = 0;
		depth[i] = 0;
		heavy[i] = -1;
		head[i] = 0;
		chain[i] = 0;
		size[i] = 0;
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
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init ();
		fr (i, 0, n - 1) {
			ll u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].pb (v);
			adj[v].pb (u);
		}
		heavylight_DFS ();
		cin >> q;
		while (q--) {
			ll a, b;
			cin >> a >> b;
			a--, b--;
			if (a == b) {
				pr (len (adj[a]));
				continue;
			}
			ll ans = 0;
			ll x = lca (a, b);
			ll tmp = a;
			while (tmp != x) {
				if (tmp == a)
					ans += (len (adj[tmp]) - 1);
				else {
					ans += (len (adj[tmp]) - 2);
				}
				tmp = parent[tmp];
			}
			tmp = b;
			while (tmp != x) {
				if (tmp == b)
					ans += len (adj[tmp]) - 1;
				else {
					ans += len (adj[tmp]) - 2;
				}
				tmp = parent[tmp];
			}
			if (a == x or b == x)
				ans += len (adj[x]) - 1;
			else
				ans += len (adj[x]) - 2;
			pr (ans);
		}
	}
	return 0;
}
