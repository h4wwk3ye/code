
/*
				C++
				encoding:UTF-8
				Modified: <16/Jun/2019 03:00:30 PM>

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
#define		 endl                   "\n";
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

const ll N = 3e5 + 5;
ve< ll > adj[N];
ll n, qu;
ll parent[N], depth[N], heavy[N], head[N], chain[N], size[N];
unordered_set< ll > path;
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
	ios_base::sync_with_stdio (false), cin.tie (0);
	ll tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> qu;
		map< pii, ll > already;
		init ();
		fr (i, 0, n - 1) {
			ll u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].pb (v);
			adj[v].pb (u);
		}
		heavylight_DFS ();
		while (qu--) {
			path.clear ();
			ll a, b;
			cin >> a >> b;
			a--, b--;
			if (already.find ({a, b}) != already.end ()) {
				ll ans = already[{a, b}];
				pr1 (ans);
				continue;
			}
			ll x = lca (a, b);
			ll tmp = a;
			while (tmp != x) {
				path.insert (tmp);
				tmp = parent[tmp];
			}
			tmp = b;
			while (tmp != x) {
				path.insert (tmp);
				tmp = parent[tmp];
			}

			path.insert (x);
			ans = 0;
			for (auto p : path) {
				ve< ll > curr;
				for (auto q : adj[p]) {
					if (path.find (q) == path.end ()) {
						if (size[q] < size[p]) {
							curr.pb (size[q]);
						} else {
							curr.pb (size[0] - size[p]);
						}
					}
				}
				fr (i, 0, len (curr)) {
					ans += curr[i];
					ll tmp = 0;
					fr (j, i + 1, len (curr)) {
						tmp += curr[i] * curr[j];
					}
					ans += tmp;
				}
				// test;
			}
			ans += len (path);
			pr1 (ans);
			already[{a, b}] = ans;
		}
	}
	return 0;
}

/*
1
14 20
1 2
2 3
2 4
4 5
4 6
1 7
7 8
7 9
9 10
1 11
11 12
1 13
13 14
*/
