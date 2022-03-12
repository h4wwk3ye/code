/*
				C++
				encoding: UTF-8
				Last Modified: 01/Mar/20 06:10:37 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
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

int n, q;
const int N = 5e5 + 5;
int arr[N];
int tree[4 * N][26];

#define left 2 * node
#define right left + 1


void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][arr[start]]++;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);

	fr (i, 0, 26) {
		tree[node][i] = tree[left][i] + tree[right][i];
	}
}

void update (int idx, int val, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][arr[idx]]--;
		arr[idx] = val;
		tree[node][arr[idx]]++;
		return;
	}
	int mid = (start + end) / 2;
	if (start <= idx and idx <= mid)
		update (idx, val, left, start, mid);
	else
		update (idx, val, right, mid + 1, end);

	fr (i, 0, 26) {
		tree[node][i] = tree[left][i] + tree[right][i];
	}
}

int final[26];

void query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or end < l or start > r) {
		return;
	}
	if (start >= l and end <= r) {
		fr (i, 0, 26) final[i] += tree[node][i];
		// return tree[node];
		return;
	}
	int mid = (start + end) >> 1;

	query (l, r, left, start, mid);
	query (l, r, right, mid + 1, end);
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	string s;
	cin >> s;
	fr (i, 1, n + 1) {
		arr[i] = s[i - 1] - 'a';
	}
	build ();
	int tc;
	cin >> tc;
	while (tc--) {
		int t;
		cin >> t;
		if (t == 1) {
			int idx;
			char c;
			cin >> idx >> c;
			int x = c - 'a';
			update (idx, x);
		} else {
			int l, r;
			cin >> l >> r;

			fill (final, final + 26, 0);
			query (l, r);
			// pr (final);
			int ans = 0;
			fr (i, 0, 26) {
				if (final[i] != 0) ans++;
			}
			pr (ans);
		}
	}
	return 0;
}
