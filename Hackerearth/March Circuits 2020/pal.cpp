//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 28/Mar/20 04:44:03 PM
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

const int N = 2e5 + 5;
string arr[N], tree[4 * N];
int n, q;

#define left 2 * node
#define right 2 * node + 1

void build (int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) >> 1;
	build (left, start, mid);
	build (right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

void update (int idx, string& val, int node = 1, int start = 1, int end = n) {
	if (start == end) {
		tree[node] = val;
		arr[idx] = val;
		return;
	}
	int mid = (start + end) >> 1;
	if (idx <= mid)
		update (idx, val, left, start, mid);
	else
		update (idx, val, right, mid + 1, end);
	tree[node] = tree[left] + tree[right];
}

string query (int l, int r, int node = 1, int start = 1, int end = n) {
	if (start > end or start > r or end < l) return "";
	if (start >= l and end <= r) return tree[node];
	int mid = (start + end) >> 1;
	return query (l, r, left, start, mid) + query (l, r, right, mid + 1, end);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> q;
	fr (i, 1, n + 1) {
		string s;
		cin >> s;
		arr[i] = s;
	}

	auto CountPS = [](string& str) {
		int n = len (str);
		int dp[n][n];
		memset (dp, 0, sizeof (dp));

		bool P[n][n];
		memset (P, false, sizeof (P));

		for (int i = 0; i < n; i++)
			P[i][i] = true;

		for (int i = 0; i < n - 1; i++) {
			if (str[i] == str[i + 1]) {
				P[i][i + 1] = true;
				dp[i][i + 1] = 1;
			}
		}

		for (int gap = 2; gap < n; gap++) {
			for (int i = 0; i < n - gap; i++) {
				int j = gap + i;

				if (str[i] == str[j] && P[i + 1][j - 1]) P[i][j] = true;

				if (P[i][j] == true)
					dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1 - dp[i + 1][j - 1];
				else
					dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
			}
		}
		return dp[0][n - 1];
	};

	build ();
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i;
			string s;
			cin >> i >> s;
			update (i, s);
		} else {
			int l, r;
			cin >> l >> r;
			string x = query (l, r);
			pr (x);
			int ans = CountPS (x);
			pr (ans);
		}
	}
	return 0;
}