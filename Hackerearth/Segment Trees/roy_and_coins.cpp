/*
				C++
				encoding: UTF-8
				Modified: <02/Sep/2019 06:28:18 PM>

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

int n, m;
const int N = 1e6 + 5;
int arr[N], tree[4 * N], lazy[4 * N];
int counter[4 * N];

void update (int l, int r, int node = 1, int start = 1, int end = n) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (start > r or end < l) return;
	if (start >= l and end <= r) {
		tree[node] += (end - start + 1);
		if (start != end) {
			lazy[2 * node]++;
			lazy[2 * node + 1]++;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update (l, r, 2 * node, start, mid);
	update (l, r, 2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void query (int node = 1, int start = 1, int end = n) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1) * lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (start == end) {
		counter[tree[node]]++;
		return;
	}
	int mid = (start + end) >> 1;
	query (2 * node, start, mid);
	query (2 * node + 1, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		update (l, r);
	}
	query ();

	dfr (i, 4 * N, 0) counter[i] += counter[i + 1];

	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		pr (counter[x]);
	}
	return 0;
}
