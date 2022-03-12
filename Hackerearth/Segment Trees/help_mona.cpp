/*
				C++
				encoding: UTF-8
				Modified: <09/Sep/2019 08:57:25 PM>

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
const int N = 2e6 + 5;
int arr[N];
int tree[4 * N];

#define left 2 * node
#define right left + 1


void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = arr[start] & 1;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

void update (int idx, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		arr[idx]++;
		tree[node] = arr[idx] & 1;
		return;
	}
	int mid = (start + end) >> 1;
	if (start <= idx and idx <= mid)
		update (idx, left, start, mid);
	else
		update (idx, right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

int query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or end < l or start > r) return 0;
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	return query (l, r, left, start, mid) + query (l, r, right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int idx;
			cin >> idx;
			update (idx);
		} else {
			int k;
			cin >> k;
			int c = query (1, n);

			if (c < k) {
				cout << -1 << endl;
				continue;
			}
			int curr = k;
			int low = 1, high = n;
			while (low <= high) {
				int mid = (low + high) >> 1;
				int a = query (low, mid);
				// pr (low, mid, high, curr, a);
				if (a == curr) break;
				if (a < curr) {
					curr -= a;
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			while (low <= high) {
				int mid = (low + high) >> 1;
				int a = query (low, mid);
				// pr (low, mid, high, curr, a);
				if (a == curr) {
					high = mid - 1;
				} else {
					low = mid + 1;
					curr -= a;
				}
			}
			cout << low << endl;
		}
	}
	return 0;
}
