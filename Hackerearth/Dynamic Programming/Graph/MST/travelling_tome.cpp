/*
				C++
				encoding:UTF-8
				Modified: <31/Mar/2019 10:22:25 PM>

				✪ H4WK3yE乡
				Mohd. Farhan Tahir
				Indian Institute Of Information Technology (IIIT),Gwalior
*/

#include <bits/stdc++.h>

using namespace std;

// clang-format off

#define		 ll                     int64_t
#define		 mod                    1000000007
#define		 ve                     vector
#define		 pb                     push_back
#define		 umap                   unordered_map
#define		 pq                     priority_queue
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<ll, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 sum(v)                 accumulate(v.begin(), v.end(), (ll)0);
#define		 pr1(x)                 cout<<x<<"\n"
#define		 pr2(x, y)              cout<<x<<" "<<y<<"\n"
#define		 pr3(x, y, z)           cout<<x<<" "<<y<<" "<<z<<"\n";
#define		 prv(v, s, n)           fr(i, s, n) cout<<v[i]<<" "; cout<<"\n";
#define		 fr(i, s, n)            for (int i = s ; i < n ; i++)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; i--)

ll powermod(ll _a,ll _b,ll _m) {ll _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}

// clang-format on


#define pil pair< ll, pair< int, int > >

const int N = 1e5 + 5;
ve< int > graph[N];
ve< pil > edges;
int Parent[N], Rank[N];
ll cost;
int visited[N];

void dfs (int node) {
	visited[node] = 1;
	for (int to : graph[node])
		if (!visited[to]) dfs (to);
}

void init () {
	fr (i, 0, N) Parent[i] = i;
}

int Find (int x) {
	if (Parent[x] != x) Parent[x] = Find (Parent[x]);
	return Parent[x];
}

void Union (int x, int y) {
	int x_id = Find (x);
	int y_id = Find (y);
	if (x_id == y_id) return;
	if (Rank[x_id] > Rank[y_id])
		Parent[y_id] = x_id;
	else {
		Parent[x_id] = y_id;
		if (Rank[x_id] == Rank[y_id]) Rank[y_id]++;
	}
}

void kruskal () {
	ll weight;
	int u, v;
	for (auto edge : edges) {
		weight = edge.ff;
		u = edge.ss.ff;
		v = edge.ss.ss;
		if (Find (u) != Find (v)) {
			cost += weight;
			Union (u, v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio (false), cin.tie (0);
	init ();
	int n, m, k;
	cin >> n >> m >> k;
	int token[k + 1];
	fr (i, 1, k + 1) cin >> token[i];

	edges.resize (m);
	fr (i, 0, m) {
		int u, v, l;
		cin >> u >> v >> l;
		ll sum = 0;
		fr (i, 0, l) {
			int x;
			cin >> x;
			sum += token[x];
		}
		graph[u].pb (v);
		graph[v].pb (v);
		edges[i] = {sum, {u, v}};
	}

	dfs (1);

	fr (i, 1, n + 1) if (!visited[i]) {
		pr1 (-1);
		return 0;
	}

	sort (all (edges));

	kruskal ();

	pr1 (cost);
	return 0;
}
