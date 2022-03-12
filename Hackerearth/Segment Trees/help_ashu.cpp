/*
				C++
				encoding: UTF-8
				Modified: <02/Sep/2019 05:30:08 PM>

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
int n, q;
const int N = 1e5 + 5;
int arr[N];
pii tree[4 * N];

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		if (arr[start] % 2) {
			tree[node].ss++;
		} else {
			tree[node].ff++;
		}
		return;
	}
	int mid = (start + end) >> 1;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);
	tree[node].ff = tree[2 * node].ff + tree[2 * node + 1].ff;
	tree[node].ss = tree[2 * node].ss + tree[2 * node + 1].ss;
}

pii query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (l > end or r < start) {
		pii ans = {0, 0};
		return ans;
	}
	if (l <= start and r >= end) {
		return tree[node];
	}
	int mid = (start + end) >> 1;
	pii a = query (l, r, 2 * node, start, mid);
	pii b = query (l, r, 2 * node + 1, mid + 1, end);
	pii ans;
	ans.ff = a.ff + b.ff;
	ans.ss = a.ss + b.ss;
	return ans;
}

void update (int idx, int val, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		arr[start] = val;
		if (val % 2) {
			tree[node].ss++;
			tree[node].ff--;
		} else {
			tree[node].ff++;
			tree[node].ss--;
		}
		return;
	}

	int mid = (start + end) >> 1;
	if (idx <= mid)
		update (idx, val, 2 * node, start, mid);
	else
		update (idx, val, 2 * node + 1, mid + 1, end);

	tree[node].ff = tree[2 * node].ff + tree[2 * node + 1].ff;
	tree[node].ss = tree[2 * node].ss + tree[2 * node + 1].ss;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			pii ans = query (l, r);
			cout << ans.ff << endl;
		} else if (t == 2) {
			int l, r;
			cin >> l >> r;
			pii ans = query (l, r);
			cout << ans.ss << endl;
		} else {
			int x, y;
			cin >> x >> y;
			if (arr[x] % 2 == y % 2) continue;
			update (x, y);
		}
	}
	return 0;
}
