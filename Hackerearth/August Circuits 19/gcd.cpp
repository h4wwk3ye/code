/*
				C++
				encoding: UTF-8
				Modified: <29/Aug/2019 12:23:29 PM>

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

#define         int                    long long
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

const int N = 2e5 + 5;
int n, m;
int arr[N], gcd_tree[4 * N], sum_tree[4 * N];

int build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		gcd_tree[node] = arr[start];
		return gcd_tree[node];
	}
	int mid = (start + end) >> 1;
	gcd_tree[node] = __gcd (build (2 * node, start, mid), build (2 * node + 1, mid + 1, end));
	return gcd_tree[node];
}

int query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (end < l or start > r) return 0;
	if (start >= l and end <= r) return gcd_tree[node];

	int mid = (start + end) >> 1;
	return __gcd (query (l, r, 2 * node, start, mid), query (l, r, 2 * node + 1, mid + 1, end));
}

/*
int build2 (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		sum_tree[node] = arr[start];
		return sum_tree[node];
	}
	int mid = (start + end) >> 1;
	sum_tree[node] = query (start, mid) + query (mid + 1, end);
	return sum_tree[node];
}

int query2 (int l, int r, int node = 1, int start = 1, int end = n) {
	if (end < l or start > r) return 0;
	if (start >= l and end <= r) return sum_tree[node];

	int mid = (start + end) >> 1;
	return query2 (l, r, )
}*/

signed main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	fr (i, 1, n + 1) cin >> arr[i];

	build ();

	// build2 ();


	while (m--) {
		int l, r;
		cin >> l >> r;
		int ans = 0;
		int curr = 1;
		fr (i, l, r + 1) {
			ans += query (i, r) * curr;
			curr++;
		}
		pr (ans);

		ans = 0;
		fr (i, l, r + 1) {
			fr (j, i, r + 1) {
				ans += query (i, j);
				pr (i, j);
			}
		}
		pr (ans);
	}
	return 0;
}
