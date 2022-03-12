#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;

pair< int, int > Parent[N];
int Rank[N];
bool bipartite[N];

pair< int, int > find_parent (int v) {
	if (v != Parent[v].first) {
		int parity = Parent[v].second;
		Parent[v] = find_parent (Parent[v].first);
		Parent[v].second ^= parity;
	}
	return Parent[v];
}

void union_set (int a, int b) {
	pair< int, int > pa = find_parent (a);
	a = pa.first;
	int x = pa.second;

	pair< int, int > pb = find_parent (b);
	b = pb.first;
	int y = pb.second;

	if (a == b) {
		if (x == y) bipartite[a] = false;
	} else {
		if (Rank[a] < Rank[b]) swap (a, b);
		Parent[b] = make_pair (a, x ^ y ^ 1);
		bipartite[a] &= bipartite[b];
		if (Rank[a] == Rank[b]) ++Rank[a];
	}
}

bool is_bipartite (int v) {
	return bipartite[find_parent (v).first];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) { // initializing
		Parent[i] = {i, 0};		   // parent and parity
		Rank[i] = 0;
		bipartite[i] = true; // each individual component is bipartite initially
	}

	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (u > v) swap (u, v);
		if (t == 1) {
			union_set (u, v);
		} else {
			bool ans = (is_bipartite (u) & is_bipartite (v) & bipartite[u] & bipartite[v]);
			cout << (ans ? "Yes\n" : "No\n");
		}
	}
	return 0;
}