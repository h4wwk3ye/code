/*
				C++
				encoding: UTF-8
				Modified: <08/Oct/2019 02:23:27 PM>

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

const int N = 8e3 + 5;
ve< int > graph[N];
int n;
int euler[N];
int tree[N];
int lvl[N];
int arr[N];
int idx;

void euler_tour (int node, int p, int l) {
	euler[idx] = node;
	lvl[idx] = l;
	if (!arr[node]) {
		arr[node] = idx;
	}
	idx++;
	for (int to : graph[node]) {
		if (to == p) continue;
		euler_tour (to, node, l + 1);
		lvl[idx] = l;
		euler[idx] = node;
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

int lca (int l, int r, int node = 1, int start = 1, int end = 2 * n) {
	if (start > end or l > end or r < start) return 1e9;
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	int a = lca (l, r, left, start, mid);
	int b = lca (l, r, right, mid + 1, end);
	if (a == 1e9) return b;
	if (b == 1e9) return a;

	return (lvl[a] < lvl[b] ? a : b);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	auto init = [&]() -> void {
		fr (i, 0, 8 * n + 2) {
			graph[i].clear ();
			euler[i] = 0;
			tree[i] = 0;
			lvl[i] = 0;
			idx = 1;
			arr[i] = 0;
		}
	};

	fr (TC, 1, tc + 1) {
		cout << "Case"
			 << " " << TC << ":\n";
		cin >> n;
		init ();
		fr (i, 1, n + 1) {
			int m;
			cin >> m;
			fr (j, 1, m + 1) {
				int v;
				cin >> v;
				graph[i].pb (v);
				graph[v].pb (i);
			}
		}
		euler_tour (1, 1, 1);

		build ();

		int q;
		cin >> q;
		while (q--) {
			int u, v;
			cin >> u >> v;
			if (arr[u] > arr[v]) swap (u, v);
			// pr (arr[u], arr[v]);
			int idx = lca (arr[u], arr[v]);
			pr (euler[idx]);
		}
	}
	return 0;
}
