//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Feb/20 08:49:57 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		ve< int > num (n + 10, 1), den (n + 10, 1);
		fr (i, 0, m) {
			int x, y, k;
			cin >> x >> y >> k;
			num[x] *= k;
			den[y + 1] *= k;
		}
		int t = 0;
		fr (i, 1, n + 1) {
			num[i] = num[i] * num[i - 1];
			den[i] = den[i] * den[i - 1];
			if (num[i] == 1 and den[i] == 1)
				t += 10;
			else
				t += (10 * num[i] / den[i]);
		}
		int ans = t / n;
		pr (ans);
	}
	return 0;
}