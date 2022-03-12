/*
				C++
				encoding: UTF-8
				Modified: <03/Sep/2019 05:51:03 PM>

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

const int N = 1e6 + 5;
int n;
int tree[4 * N], lazy[4 * N];

#define left 2 * node
#define right left + 1

void relax (int node, int start, int end) {
	if (!lazy[node]) return;
	tree[node] = lazy[node];
	if (start != end) {
		lazy[left] = lazy[node];
		lazy[right] = lazy[node];
	}
	lazy[node] = 0;
}

void update_range (int l, int r, int val = 1, int node = 1, int start = 1, int end = N) {
	if (start > end) return;
	relax (node, start, end);
	if (start > r or end < l) return;
	if (start >= l and end <= r) {
		lazy[node] = val;
		relax (node, start, end);
		return;
	}
	int mid = (start + end) >> 1;
	update_range (l, r, val, left, start, mid);
	update_range (l, r, val, right, mid + 1, end);
	tree[node] = max (tree[left], tree[right]);
}

int query (int l, int r, int node = 1, int start = 1, int end = N) {
	if (start > end) return 0;
	relax (node, start, end);
	if (start > r or end < l) return 0;
	if (start >= l and end <= r) {
		return tree[node];
	}
	int mid = (start + end) >> 1;
	return max (query (l, r, left, start, mid), query (l, r, right, mid + 1, end));
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// freopen ("inp2.txt", "r", stdin);
	cin >> n;
	fr (i, 1, n + 1) {
		int l, h, p, c, x;
		cin >> l >> h >> p >> c >> x;
		l--;
		if (c == 1) {
			int a = query (x, x + l);
			update_range (x, x + l, a + 1);
			update_range (x + p - 1, x + p - 1, a + h + 1);
		} else {
			int a = query (x, x + p - 2);
			int b = query (x + p - 1, x + p - 1);
			int c = query (x + p, x + l);

			b += h;
			if (b >= a and b >= c) {
				update_range (x, x + l, b + 1);
			} else if (a >= b and a >= c) {
				update_range (x, x + l, a + 1);
			} else {
				update_range (x, x + l, c + 1);
			}
		}
	}
	// fr (i, 12, 30) cout << query (i, i) << " ";
	pr (query (1, N));
	return 0;
}
