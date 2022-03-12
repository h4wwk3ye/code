/*
				C++
				encoding: UTF-8
				Modified: <04/Sep/2019 12:57:14 PM>

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

const int N = 1e5 + 5;
int arr[N], d[N];
int tree[4 * N];
pii lazy[4 * N];
int day[N];
int n;

#define left node * 2
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node] = max (tree[left], tree[right]);
}

void relax (int node, int start, int end) {
	if (!lazy[node].ff) return;
	int tmp = max (0, tree[node] - lazy[node].ff);
	day[++lazy[node].ss] += min (lazy[node].ff, tree[node]);
	tree[node] -= tmp;
	if (start != end) {
		lazy[left].ff = lazy[right].ff = lazy[node].ff;
	}
	lazy[node].ff = 0;
}

void update (int l, int r, int val, int node = 1, int start = 1, int end = n) {
	if (start > end) return;

	relax (node, start, end);
	if (start > r or end < l) return;

	if (start >= l and end <= r) {
		lazy[node].ff += val;
		relax (node, start, end);
		return;
	}
	int mid = (start + end) >> 1;
	update (l, r, val, left, start, mid);
	update (l, r, val, right, mid + 1, end);
	tree[node] = max (tree[left], tree[right]);
}

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 1, n + 1) cin >> d[i];
	build ();
	fr (i, 1, n + 1) {
		pr (i);
		update (1, i, d[i]);
	}
	fr (i, 1, n + 1) cout << day[i] << " ";
	cout << endl;
	return 0;
}
