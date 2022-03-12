/*
				C++
				encoding: UTF-8
				Modified: <30/Aug/2019 08:17:34 PM>

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

const int N = 150000 + 5;
int arr[N];
int tree[4 * N];

void build (int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build (2 * node, start, mid);
	build (2 * node + 1, mid + 1, end);

	tree[node] = min (tree[2 * node], tree[2 * node + 1]);
}

int query (int node, int start, int end, int l, int r) {
	if (start > r or end < l) return 2e9 - 5;
	if (start >= l and end <= r) return tree[node];

	int mid = (start + end) / 2;

	return min (query (2 * node, start, mid, l, r), query (2 * node + 1, mid + 1, end, l, r));
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		fr (i, 1, n + 1) cin >> arr[i];
		build (1, 1, n);
		int x = 0;
		fr (i, 1, n + 1) {
			int ans = query (1, 1, n, i + 1, n);
			if (ans < arr[i]) x++;
		}
		pr (x);
	}
	return 0;
}
