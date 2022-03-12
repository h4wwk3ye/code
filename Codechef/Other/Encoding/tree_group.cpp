#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 31/Oct/19 11:57:00 AM
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

const int N = 5e4 + 5;
ve< int > graph[N];
int n, t = -1;
int a[N];
int pre[N], post[N];
ve< int > arr;
int ans[N], freq[4 * N], cnt[4 * N];

void dfs (int node, int parent) {
	pre[node] = ++t;
	arr.pb (a[node]);
	for (int to : graph[node]) {
		if (to != parent) dfs (to, node);
	}
	arr.pb (a[node]);
	post[node] = ++t;
}

ve< ve< int > > queries;
int L = 300;

bool cmp (ve< int >& a, ve< int >& b) {
	if (a[0] / L == b[0] / L) return a[1] < b[1];
	return a[0] < b[0];
}

int mx;

void add (int i) {
	cnt[freq[arr[i]]]--;
	freq[arr[i]]++;
	cnt[freq[arr[i]]]++;
	while (cnt[mx + 1] > 0)
		mx++;
}

void remove (int i) {
	cnt[freq[arr[i]]]--;
	freq[arr[i]]--;
	cnt[freq[arr[i]]]++;
	while (mx > 0 and cnt[mx] == 0)
		mx--;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;

	fr (i, 1, n + 1) cin >> a[i];
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);

	fr (i, 1, n + 1) {
		queries.pb ({pre[i], post[i], i});
	}

	sort (all (queries), cmp);

	int mo_left = 0, mo_right = -1;

	for (auto& q : queries) {
		int l = q[0], r = q[1], idx = q[2];

		while (mo_left < l) {
			remove (mo_left);
			mo_left++;
		}
		while (mo_left > l) {
			mo_left--;
			add (mo_left);
		}
		while (mo_right > r) {
			remove (mo_right);
			mo_right--;
		}
		while (mo_right < r) {
			mo_right++;
			add (mo_right);
		}
		ans[idx] = mx;
	}

	fr (i, 1, n + 1) {
		cout << ans[i] / 2 << " ";
	}
	cout << endl;
	return 0;
}