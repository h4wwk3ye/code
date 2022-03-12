/*
				C++
				encoding:UTF-8
				Modified: <20/Jun/2019 11:43:55 PM>

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

const ll N = 1e3 + 5;
ve< ll > graph[N], graph_r[N];
ll vis[N], vis_other[N];
ve< ll > stk;
ll n, m;
ll arr[N];
ve< ll > s1;

void init () {
	fr (i, 1, n + 1) {
		graph[i].clear ();
		graph_r[i].clear ();
		vis[i] = 0;
		vis_other[i] = 0;
		arr[i] = 0;
	}
	stk.clear ();
	s1.clear ();
}

void dfs (ll node) {
	vis[node] = 1;
	for (ll to : graph_r[node]) {
		if (!vis[to]) dfs (to);
	}
	stk.pb (node);
}

ll dfs_1 (ll node) {
	ll curr = arr[node];
	vis_other[node] = 1;
	for (ll to : graph[node]) {
		if (!vis_other[to]) {
			curr += dfs_1 (to);
		}
	}
	return curr;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		init ();
		fr (i, 1, n + 1) cin >> arr[i];
		fr (i, 0, m) {
			ll u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph_r[v].pb (u);
		}
		fr (i, 1, n + 1) {
			if (!vis[i]) dfs (i);
		}
		reverse (all (stk));
		for (ll node : stk) {
			if (!vis_other[node]) {
				ll ans;
				ans = dfs_1 (node);
				s1.pb (ans);
			}
		}
		ll ans = 0;
		sort (all (s1));
		ll curr = 1;
		for (auto x : s1) {
			ans += curr * x;
			curr++;
		}
		pr1 (ans);
	}
	return 0;
}
