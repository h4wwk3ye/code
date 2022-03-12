/*
				C++
				encoding: UTF-8
				Modified: <02/Oct/2019 09:48:43 AM>

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
const int N = 1e5 + 5;
int arr[N];
unordered_map< int, int > tree[4 * N];

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
	for (auto i : tree[left]) {
		tree[node][i.ff] += i.ss;
	}
	for (auto i : tree[right]) {
		tree[node][i.ff] += i.ss;
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
	tree[node].clear ();
	for (auto i : tree[left]) {
		tree[node][i.ff] += i.ss;
	}
	for (auto i : tree[right]) {
		tree[node][i.ff] += i.ss;
	}
}

unordered_map< int, int > query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or end < l or start > r) {
		unordered_map< int, int > tmp;
		return tmp;
	}
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	unordered_map< int, int > tmp, a, b;
	tmp.max_load_factor (0.25);
	a.max_load_factor (0.25);
	b.max_load_factor (0.25);
	a = query (l, r, left, start, mid);
	b = query (l, r, right, mid + 1, end);

	for (auto i : a) {
		tmp[i.ff] = i.ss;
	}
	for (auto i : b) {
		tmp[i.ff] += i.ss;
	}
	return tmp;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	n = len (s);
	fr (i, 1, n + 1) {
		arr[i] = s[i - 1] - 'a';
	}
	fr (i, 1, 4 * n + 1) tree[i].max_load_factor (0.25);
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
			unordered_map< int, int > ans = query (l, r);
			int o = 0;
			for (auto i : ans) {
				if (i.ss > 0) o++;
			}
			pr (o);
		}
	}
	return 0;
}
