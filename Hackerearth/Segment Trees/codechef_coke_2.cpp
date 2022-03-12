/*
				C++
				encoding: UTF-8
				Modified: <04/Sep/2019 10:43:48 PM>

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
pii arr[N];
int tree[4 * N], lazy[4 * N];
int n, q;

#define left 2 * node
#define right left + 1

void relax (int node, int start, int end) {
	tree[node] = min (tree[node], lazy[node]);
	if (start != end) {
		lazy[left] = min (lazy[left], lazy[node]);
		lazy[right] = min (lazy[right], lazy[node]);
	}
	lazy[node] = 1e18;
}

void update (int l, int r, int val, int node = 1, int start = 1, int end = q) {
	if (start > end) return;
	relax (node, start, end);
	if (start > r or end < l) return;

	if (start >= l and end <= r) {
		lazy[node] = min (lazy[node], val);
		relax (node, start, end);
		return;
	}

	int mid = (start + end) >> 1;
	update (l, r, val, left, start, mid);
	update (l, r, val, right, mid + 1, end);
	tree[node] = min (tree[node], min (tree[left], tree[right]));
}

int query (int idx, int node = 1, int start = 1, int end = q) {
	if (start > end) return 1e18;

	relax (node, start, end);
	if (start == end) return tree[node];
	int mid = (start + end) >> 1;

	if (idx <= mid)
		return query (idx, left, start, mid);
	else
		return query (idx, right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int k, l, r;
		cin >> n >> q >> k >> l >> r;
		fr (i, 1, 4 * q + 1) {
			tree[i] = 1e18;
			lazy[i] = 1e18;
		}
		fr (i, 1, n + 1) cin >> arr[i].ff >> arr[i].ss;

		if (k < l) {
			fr (i, 1, n + 1) {
				int l1, r1;
				if (arr[i].ff < l)
					continue;
				else if (arr[i].ff >= l and arr[i].ff <= r) {
					l1 = 1;
					r1 = arr[i].ff - l;
				} else {
					l1 = arr[i].ff - r;
					r1 = arr[i].ff - l;
				}
				l1 = max (1LL, l1);
				r1 = min (r1, q);
				if (l1 <= q and r1 >= 1) update (l1, r1, arr[i].ss);
			}
		} else if (k > r) {
			fr (i, 1, n + 1) {
				int l1, r1;
				if (arr[i].ff > r)
					continue;
				else if (arr[i].ff >= l and arr[i].ff <= r) {
					l1 = 1;
					r1 = r - arr[i].ff;
				} else {
					l1 = l - arr[i].ff;
					r1 = r - arr[i].ff;
				}
				l1 = max (1LL, l1);
				r1 = min (r1, q);
				if (l1 <= q and r1 >= 1) update (l1, r1, arr[i].ss);
			}
		} else {
			fr (i, 1, n + 1) {
				int l1, r1;
				if (arr[i].ff < l) {
					l1 = l - arr[i].ff;
					r1 = q;
				} else if (arr[i].ff >= l and arr[i].ff <= r) {
					l1 = 1;
					r1 = q;
				} else {
					l1 = arr[i].ff - r;
					r1 = q;
				}
				l1 = max (1LL, l1);
				r1 = min (r1, q);
				if (l1 <= q and r1 >= 1) update (l1, r1, arr[i].ss);
			}
		}

		fr (m, 1, q + 1) {
			int ans = query (m);
			if (ans == 1e18) ans = -1;
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}
