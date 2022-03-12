/*
				C++
				encoding: UTF-8
				Modified: <03/Sep/2019 11:18:53 PM>

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

#define		 ll                     long long
#define		 ve                     vector
#define		 pb                     push_back
#define		 endl                   "\n";
#define		 ff                     first
#define		 ss                     second
#define		 pii                    pair<int, int>
#define		 len(v)                 int(v.size())
#define		 all(v)                 v.begin(), v.end()
#define		 reset(a, b)            memset(a, b, sizeof(a));
#define		 fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		 dfr(i, s, n)           for (int i = s ; i > n ; --i)

void pr () {
	cout << "\n";
}

template < typename T, typename... ARGS > void pr (const T& t, ARGS... args) {
	cout << t << " ";
	pr (args...);
}

// clang-format on

const int N = 1e5 + 5;
int arr[N];
pii tree[4 * N];
int lazy[4 * N];
int n;

#define left node * 2
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node].ff = tree[node].ss = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node].ff = min (tree[left].ff, tree[right].ff);
	tree[node].ss = max (tree[left].ss, tree[right].ss);
}

void relax (int node, int start, int end) {
	if (!lazy[node]) return;
	tree[node].ff -= lazy[node];
	tree[node].ss -= lazy[node];
	if (start != end) {
		lazy[left] += lazy[node];
		lazy[right] += lazy[node];
	}
	lazy[node] = 0;
}

void update (int x, int l = 1, int r = n, int node = 1, int start = 1, int end = n) {
	if (start > end) return;
	relax (node, start, end);
	if (tree[node].ff > x) {
		lazy[node]++;
		relax (node, start, end);
		return;
	}
	if (tree[node].ss <= x) return;

	int mid = (start + end) >> 1;
	update (x, l, r, left, start, mid);
	update (x, l, r, right, mid + 1, end);

	tree[node].ff = min (tree[left].ff, tree[right].ff);
	tree[node].ss = max (tree[left].ss, tree[right].ss);
}

void compute (int node = 1, int start = 1, int end = n) {
	relax (node, start, end);
	if (start == end) {
		arr[start] = tree[node].ff;
		return;
	}
	int mid = (start + end) >> 1;
	compute (left, start, mid);
	compute (right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();
	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		update (x);
	}
	compute ();
	fr (i, 1, n + 1) cout << arr[i] << " ";
	cout << endl;
	return 0;
}
