/*
				C++
				encoding: UTF-8
				Modified: <03/Sep/2019 12:54:04 AM>

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

#define         int                    long long
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
    cout << t << " ";
    pr (args...);
}

// clang-format on

const int N = 1e5 + 5;
ve< int > graph[N];
int n, m, root;
int tree[4 * N], lazy[4 * N];
int t = 0, pre[N], post[N];
int arr[N];
int toplogical[N];

void dfs (int node, int parent) {
	pre[node] = ++t;
	toplogical[t] = node;
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
	}
	post[node] = t;
}

#define left 2 * node
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = arr[toplogical[start]];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

void propagate (int node, int start, int end) {
	if (lazy[node]) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[left] += lazy[node];
			lazy[right] += lazy[node];
		}
		lazy[node] = 0;
	}
}

void update (int l, int r, int val, int node = 1, int start = 1, int end = n) {
	if (start > end) return;

	propagate (node, start, end);

	if (end < l or start > r) return;

	if (start >= l and end <= r) {
		tree[node] += (end - start + 1) * val;
		if (start != end) {
			lazy[left] += val;
			lazy[right] += val;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update (l, r, val, left, start, mid);
	update (l, r, val, right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

int query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or end < l or start > r) return 0;

	propagate (node, start, end);

	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	return query (l, r, left, start, mid) + query (l, r, right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, n + 1) cin >> arr[i];

	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}

	dfs (1, 1);

	build ();

	while (m--) {
		int tp, u, v;
		cin >> tp >> u >> v;
		if (tp == 1) {
			int ans = query (pre[u], post[u]);
			if (ans & 1)
				update (pre[u], post[u], 1);
			else
				update (pre[u], post[u], v);
		} else {
			int a = query (pre[u], post[u]);
			int b = query (pre[v], post[v]);
			cout << (a ^ b) << endl;
		}
	}
	return 0;
}
