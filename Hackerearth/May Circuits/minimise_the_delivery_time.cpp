/*
				C++
				encoding:UTF-8
				Modified: <28/May/2019 12:24:23 AM>

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
#define		 pii                    pair<int, int>
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

int n, m;
const int N = 1e5 + 5;
ve< int > graph[N];
map< pii, pii > mp;
ll ans = 2e18;
ll visited[N], dist[N], parent[N];

void dijkstra () {
	fill (dist, dist + N, 2e18);
	dist[1] = 0;
	set< pii > s;
	s.insert ({0, 1});
	while (!s.empty ()) {
		auto p = *s.begin ();
		s.erase (s.begin ());
		int x = p.ss, w = p.ff;
		if (visited[x]) continue;
		visited[x] = 1;
		for (int to : graph[x]) {
			int a = min (x, to);
			int b = max (x, to);
			int t = mp[{a, b}].ff;
			if (dist[x] + t < dist[to]) {
				parent[to] = x;
				s.insert ({dist[to], to});
				dist[to] = t + dist[x];
			}
		}
	}
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n >> m;
	fr (i, 0, m) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v) swap (u, v);
		if (mp.find ({u, v}) != mp.end ()) {
			if (w < mp[{u, v}].ff) mp[{u, v}] = {w, i + 1};
		} else {
			graph[u].pb (v);
			graph[v].pb (u);
			mp[{u, v}] = {w, i + 1};
		}
	}
	/*if (mp.find ({1, n}) != mp.end ()) {
		pr1 (1);
		pr2 (1, (mp[{1, n}].ss));
	}*/
	dijkstra ();
	ve< int > path;
	int i = n;
	while (parent[i] != 0) {
		int a = i;
		int b = parent[i];
		if (a > b) swap (a, b);
		path.pb (mp[{a, b}].ss);
		i = parent[i];
	}
	sort (all (path));
	pr1 (1);
	cout << len (path) << " ";
	for (int x : path)
		cout << x << " ";
	return 0;
}
