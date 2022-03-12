/*
				C++
				encoding:UTF-8
				Modified: <03/Jun/2019 09:10:04 PM>

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

const int N = 2e5 + 5;
int n;
ve< int > graph[N];
ve< int > d[N];
int dist[N];

void dfs (int node, int parent) {
	dist[node] = 1 + dist[parent];
	d[dist[node]].pb (node);
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
	}
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (0);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dist[1] = -1;
	dfs (1, 1);
	int cnt = 36;
	int node = 1;
	while (true) {
		if () }
	return 0;
}
