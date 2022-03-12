/*
				C++
				encoding: UTF-8
				Last Modified: 10/Aug/20 09:57:11 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

const int N = 1e5 + 5;
int tree[4 * N][26];
int arr[N];
int n, q;

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][arr[start]]++;
		return;
	}

	int mid = (start + end) >> 1;

	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	for (int i = 0; i < 26; ++i) {
		tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
	}
}

void update (int index, int val, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][arr[index]]--;
		arr[index] = val;
		tree[node][arr[index]]++;
		return;
	}

	int mid = (start + end) >> 1;

	if (start <= index and index <= mid) {
		update (index, val, 2 * node, start, mid);
	} else {
		update (index, val, 2 * node + 1, mid + 1, end);
	}

	for (int i = 0; i < 26; ++i) {
		tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
	}
}

vector< int > final;

void query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or end < l or start > r) {
		return;
	}
	if (start >= l and end <= r) {
		for (int i = 0; i < 26; ++i)
			final[i] += tree[node][i];
		return;
	}

	int mid = (start + end) >> 1;

	query (l, r, 2 * node, start, mid);
	query (l, r, 2 * node + 1, mid + 1, end);
}

void init () {
	for (int i = 0; i <= 4 * n + 5; ++i) {
		for (int j = 0; j < 26; ++j) {
			tree[i][j] = 0;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		init ();
		string s;
		cin >> s;
		for (int i = 1; i <= n; ++i) {
			arr[i] = s[i - 1] - 'a';
		}
		build ();

		while (q--) {
			int t;
			cin >> t;
			if (t == 1) {
				int index;
				cin >> index;
				char ch;
				cin >> ch;

				update (index, ch - 'a');
			} else {
				int l, r, k;
				cin >> l >> r >> k;
				final.assign (26, 0);

				query (l, r);
				vector< int > x;
				for (int i = 0; i < 26; ++i) {
					while (final[i]) {
						x.push_back (i);
						final[i]--;
					}
				}

				char ans = x[k - 1] + 'a';
				print (ans);
			}
		}
	}
	return 0;
}