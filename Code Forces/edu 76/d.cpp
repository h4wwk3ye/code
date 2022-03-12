//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 14/Nov/19 03:47:41 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// clang-format off

#define		int                    long long
#define		ve                     vector
#define		pb                     push_back
#define		endl                   "\n"
#define		ff                     first
#define		ss                     second
#define		pii                    pair<int, int>
#define		len(v)                 (int)v.size()
#define		all(v)                 v.begin(), v.end()
#define		reset(a, b)            memset(a, b, sizeof(a));
#define		fr(i, s, n)            for (int i = s ; i < n ; ++i)
#define		dfr(i, s, n)           for (int i = s ; i > n ; --i)

template < typename T > void pr (const T& t) {
    cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void pr (const T& t, const U& u, const ARGS&... args) {
    cout << t << " ";
    pr (u, args...);
}

// clang-format on

const int N = 2e5 + 5;
int monster[N];
pii hero[N];
int n, m;
int tree[4 * N];

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = monster[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);
	tree[node] = max (tree[2 * node], tree[2 * node + 1]);
}

int query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end) return -1;
	if (start > l or end < r) return -1;
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	return max (query (l, r, 2 * node, start, mid), query (l, r, 2 * node + 1, mid + 1, end));
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		fr (i, 1, 4 * n + 1) tree[i] = 0;
		int MX = 0;
		fr (i, 1, n + 1) {
			cin >> monster[i];
			MX = max (MX, monster[i]);
		}
		build ();
		cin >> m;
		map< int, int > mp;
		int fl = 0;
		fr (i, 1, m + 1) {
			cin >> hero[i].ff >> hero[i].ss;
			mp[hero[i].ss] = max (hero[i].ff, mp[hero[i].ss]);
			if (hero[i].ff >= MX) fl = 1;
		}
		if (!fl) {
			pr (-1);
			continue;
		}

		int i = 1;
		int ans = 0;
		while (i < n) {
			int low = i, high = n;
			while (low <= high) {
				int mid = (low + high + 1) >> 1;
				pr (low, high, mid, "first");
				if (mp.lower_bound (mid - low) == mp.end ()) {
					high = mid - 1;
				} else {
					int f = 0;
					int m = query (low, mid);
					auto it = mp.lower_bound (mid - low + 1);
					for (; it != mp.end (); ++it) {
						if (it->ss >= m) {
							f = 1;
							break;
						}
					}
					pr (low, high, mid, f, m, "second");
					if (!f)
						high = mid - 1;
					else {
						low = mid + 1;
					}
				}
			}
			// if (low == i)
			// 	i++;
			// else
			i = low;
			pr (i);
			ans++;
		}
		pr (ans);
	}
	return 0;
}

/*
1
5
2 3 5 5 4
3
2 3
5 4
5 2

*/