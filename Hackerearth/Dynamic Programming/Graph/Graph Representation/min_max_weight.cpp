/*
				C++
				encoding:UTF-8
				Modified: <25/May/2019 09:56:18 PM>

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
#define		 aint(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (int)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n"
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n"
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

// clang-format on

const int N = 2e3 + 5;
int n, s;
ve< int > graph[N];
int dist[N], depth[N];
ve< int > leaves;
int source;

void init () {
	fr (i, 0, N) {
		graph[i].clear ();
		depth[i] = 0;
		dist[i] = 0;
	}
	leaves.clear ();
	source = 0;
}

void check (int node = 1, int parent = 1) {
	bool leaf = true;
	depth[node] = 1 + depth[parent];
	for (int to : graph[node]) {
		if (to == parent) continue;
		leaf = false;
		check (to, node);
	}
	if (leaf) leaves.pb (node);
}

void dfs (int node, int parent) {
	bool leaf = true;
	dist[node] = 1 + dist[parent];
	for (int to : graph[node]) {
		if (to == parent) continue;
		leaf = false;
		dfs (to, node);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	int tc;
	cin >> tc;
	while (tc--) {
		init ();
		cin >> n >> s;
		fr (i, 0, n - 1) {
			int u, v;
			cin >> u >> v;
			graph[u].pb (v);
			graph[v].pb (u);
		}
		depth[1] = -1;
		check ();
		int source = leaves[0];
		for (int x : leaves) {
			if (depth[x] > depth[source]) source = x;
		}
		dist[source] = -1;
		dfs (source, source);

		// prv (leaves, 0, len (leaves));
		int mx = 0;
		for (int x : leaves) {
			mx = max (mx, dist[x]);
		}
		bool possible = false;
		for (int x : leaves) {
			if (dist[x] == mx or depth[x] == depth[source]) continue;
			possible = true;
			break;
		}
		if (possible) {
			pr1 (0);
		} else {
			pr1 ((int) ceil ((double) s / (n - 1)));
		}
	}
	return 0;
}
