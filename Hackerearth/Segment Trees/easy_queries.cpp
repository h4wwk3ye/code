/*
				C++
				encoding: UTF-8
				Modified: <03/Sep/2019 07:47:03 PM>

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
const int N = 1e5 + 5;
int arr[N];
pii tree[4 * N];

#define left node
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node].ff = arr[start];
		tree[node].ss = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node].ff = max (tree[left].ff, tree[right].ff);
	tree[node].ss = min (tree[left].ss, tree[right].ss);
}

void update (int idx, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		arr[idx] = 1;
		tree[]
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) cin >> arr[i];
	build ();
	while (q--) {
		int t, idx;
		cin >> t >> idx;
		idx++;
		if (t == 1) {
			update (idx);
		}
	}
	return 0;
}
