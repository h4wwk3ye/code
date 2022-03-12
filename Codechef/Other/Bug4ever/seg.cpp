/*
				C++
				encoding: UTF-8
				Modified: <05/Oct/2019 11:21:57 AM>

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

const int N = 1e5 + 5;
int n, q;
int arr[N];
int tree[4 * N][2];

#define left 2 * node
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][0] = arr[start];
		tree[node][1] = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node][0] = tree[left][0] + tree[right][0];
	tree[node][1] = tree[left][1] * tree[right][1];
}

pii ans = {0, 1};

void query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or l > end or r < start) {
		return;
	}
	if (start >= l and end <= r) {
		ans.ff += tree[node][0];
		ans.ss *= tree[node][1];
		return;
	}
	int mid = (start + end) >> 1;
	query (l, r, left, start, mid);
	query (l, r, right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> q;
		fr (i, 0, 4 * n + 2) {
			tree[i][0] = 0;
			tree[i][1] = 0;
		}
		string s;
		cin >> s;
		fr (i, 1, n + 1) {
			if (s[i - 1] == 'O')
				arr[i] = 1;
			else
				arr[i] = 2;
		}
		build ();
		while (q--) {
			int t, l, r;
			cin >> t >> l >> r;
			ans = {0, 1};
			query (l, r);
			// pr (ans);
			if (t == 1) {
				if (ans.ff & 1) {
					pr ("O");
				} else {
					pr ("E");
				}
			} else {
				if (ans.ss & 1) {
					pr ("O");
				} else {
					pr ("E");
				}
			}
		}
	}
	return 0;
}
