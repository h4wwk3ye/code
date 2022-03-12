/*
				C++
				encoding: UTF-8
				Modified: <04/Sep/2019 06:30:16 PM>

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

const int N = 1e5 + 5;
int n;
int arr[N], cost[N];
map< int, int > tree[4 * N];

int n_factors (int x) {
	int ans = 0;

	for (int i = 1; i <= sqrt (x); ++i) {
		if (x % i == 0) {
			if (x / i == i)
				ans++;
			else
				ans += 2;
		}
	}
	return ans;
}

void merge (map< int, int >& a, map< int, int >& b, map< int, int >& c) {
	for (auto i : b) {
		a[i.ff] += i.ss;
	}
	for (auto i : c) {
		a[i.ff] += i.ss;
	}
}


#define left 2 * node
#define right left + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node][cost[start]]++;
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	merge (tree[node], tree[left], tree[right]);
}

map< int, int > tmp;

map< int, int > query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > r or end < l) return tmp;
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	map< int, int > a = query (l, r, left, start, mid);
	map< int, int > b = query (l, r, right, mid + 1, end);
	map< int, int > c;
	merge (c, a, b);
	return c;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// freopen ("inp.txt", "r", stdin);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 1, n + 1) cost[i] = n_factors (arr[i]);

	build ();

	int tc;
	cin >> tc;
	while (tc--) {
		int l, r;
		cin >> l >> r;
		map< int, int > mp = query (l, r);
		int ans = 0;
		for (auto i : mp) {
			ans += (i.ss * (i.ss - 1)) / 2;
		}
		pr (ans);
	}
	return 0;
}
