/*
				C++
				encoding: UTF-8
				Modified: <31/Jul/2019 11:11:51 AM>

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
#define         mod                    1000000007
#define         ve                     vector
#define         pb                     push_back
#define         endl                   "\n";
#define         ff                     first
#define         ss                     second
#define         pii                    pair<int, int>
#define         len(v)                 int(v.size())
#define         all(v)                 v.begin(), v.end()
#define         reset(a, b)            memset(a, b, sizeof(a));
#define         fr(i, s, n)            for (ll i = s ; i < n ; ++i)
#define         dfr(i, s, n)           for (ll i = s ; i > n ; --i)

void pr () {
    cout << "\n";
}

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

const int N = 2e5 + 5;
int n;
int arr[N], a[N], flag[N];
int tree[4 * N];

void build (int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	tree[node] = max (tree[2 * node], tree[2 * node + 1]);
}

/*void update (int node, int index, int val, int start, int end) {
	if (start == end) {
		arr[index] = val;
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;

	if (start <= index and index <= mid) {
		update (2 * node, index, val, start, mid);
	} else {
		update (2 * node + 1, index, val, mid + 1, end);
	}
	tree[node] = max (tree[2 * node], tree[2 * node + 1]);
}*/


int query (int l, int r, int node, int start, int end) {
	if (start > r or end < l) return -1e9;
	if (start >= l and end <= r) return tree[node];

	int mid = (start + end) / 2;

	return max (query (l, r, 2 * node, start, mid), query (l, r, 2 * node + 1, mid + 1, end));
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> a[i];
	int tc;
	cin >> tc;
	fr (i, 1, tc + 1) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int p, x;
			cin >> p >> x;
			a[p] = x;
			flag[p] = i;
		} else {
			int x;
			cin >> x;
			arr[i] = x;
			// update (1, i, x, 1, tc);
		}
	}
	build (1, 1, tc);
	fr (i, 1, n + 1) {
		int last_t = flag[i];
		int mx = query (last_t + 1, tc, 1, 1, tc);
		cout << max (a[i], mx) << " ";
	}

	return 0;
}
