#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, q;

pair< int, int > Parent[N];
int Rank[N];
bool bipartite[N];

void init (int v) {
	Parent[v] = {v, 0};
	Rank[v] = 0;
	bipartite[v] = true; // each individual component in bipartite
}

pair< int, int > find_set (int v) {
	if (v != Parent[v].first) {
		int color = Parent[v].second;
		Parent[v] = find_set (Parent[v].first);
		Parent[v].second = 1 - color; // inverting the color
	}
	return Parent[v];
}

void union_set (int a, int b) {
	pair< int, int > pa = find_set (a);
	pair< int, int > pb = find_set (b);
	auto [a, x] = pa;
	auto [b, y] = pb;

	if (a == b) { // same component cant be bipartite
		if (x == y) bipartite[a] = false;
	} else {
		if (Rank[a] < Rank[b]) swap (a, b);
		Parent[b] = {a, x ^ y ^ 1};
		bipartite[a] &= bipartite[b];
		if (Rank[a] == Rank[b]) ++Rank[a];
	}
}

bool is_bipartite (int v) {
	return bipartite[find_set (v).first];
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) { // initializing
		init (i);
	}

	while (q--) {
		int t, u, v;
		cin >> t >> u >> v;
		if (u > v) swap (u, v);
		if (t == 1) {
			union_set (u, v);
		} else {
			auto [u_id, u_color] = find_set (u);
			auto [v_id, v_color] = find

			bool ans = (is_bipartite (u) and is_bipartite (v));
			cout << (ans ? "Yes\n" : "No\n");
		}
	}
	return 0;
}