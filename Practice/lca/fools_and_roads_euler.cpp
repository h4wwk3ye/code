/*
				C++
				encoding: UTF-8
				Modified: <09/Oct/2019 02:01:59 PM>

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

const int N = 1e5 + 5;
ve< int > graph[N];
int euler[2 * N], lvl[2 * N], first_occ[N], tree[8 * N];
map< pii, int > edges;
int cnt[N], ans[N];
int idx = 1;
int n, k;

void euler_tour (int node, int parent, int l) {
	euler[idx] = node;
	lvl[idx] = l;
	if (!first_occ[node]) {
		first_occ[node] = idx;
	}
	idx++;
	for (int to : graph[node]) {
		if (to == parent) continue;
		euler_tour (to, node, l + 1);
		euler[idx] = node;
		lvl[idx] = l;
		idx++;
	}
}


#define left 2 * node
#define right left + 1

void build (int node = 1, int start = 1, int end = 2 * n) {
	if (start == end) {
		tree[node] = start;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	if (lvl[tree[left]] < lvl[tree[right]]) {
		tree[node] = tree[left];
	} else {
		tree[node] = tree[right];
	}
}

int query (int l, int r, int node = 1, int start = 1, int end = 2 * n) {
	if (start > end or l > end or r < start) return -1;
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	int a = query (l, r, left, start, mid);
	int b = query (l, r, right, mid + 1, end);
	if (a == -1) return b;
	if (b == -1) return a;
	return (lvl[a] < lvl[b] ? a : b);
}

int lca (int u, int v) {
	if (first_occ[u] > first_occ[v]) swap (u, v);
	int idx = query (first_occ[u], first_occ[v]);
	return euler[idx];
}

int dfs (int node, int parent) {
	int curr = 0;
	for (int to : graph[node]) {
		if (to == parent) continue;
		int x = dfs (to, node);
		ans[edges[{node, to}]] += x;
		curr += x;
	}
	return curr + cnt[node];
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
		edges[{u, v}] = i;
		edges[{v, u}] = i;
	}
	euler_tour (1, 1, 1);
	build ();
	cin >> k;
	while (k--) {
		int u, v;
		cin >> u >> v;
		int l = lca (u, v);
		cnt[l] -= 2;
		cnt[u]++;
		cnt[v]++;
	}
	dfs (1, 1);
	fr (i, 1, n) {
		cout << ans[i] << " ";
	}
	return 0;
}
