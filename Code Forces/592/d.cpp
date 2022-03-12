/*
				C++
				encoding: UTF-8
				Modified: <13/Oct/2019 04:46:30 PM>

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
#define         len(v)                 (int)v.size()
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

int n;
const int N = 1e5 + 5;
ve< int > graph[N];
int c[N][3];
int arr[N];
int root1, root2;
int f = 0;

void dfs1 (int node, int parent) {
	int cnt = 0;
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs1 (to, node);
		cnt++;
	}
	if (cnt > 1) f = 1;
}

void dfs (int node, int parent, int idx) {
	arr[idx] = node;
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node, idx + 1);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> c[i][0];
	fr (i, 1, n + 1) cin >> c[i][1];
	fr (i, 1, n + 1) cin >> c[i][2];
	fr (i, 1, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	fr (i, 1, n + 1) {
		if (len (graph[i]) == 1) {
			root1 = i;
			break;
		}
	}

	dfs1 (root1, root1);

	if (f) {
		pr (-1);
		return 0;
	}

	dfs (root1, root1, 1);

	ve< ve< int > > possible = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
	int idx = 0;
	int ans = LLONG_MAX;
	int x = 0;
	for (auto p : possible) {
		int j = 0;
		int curr = 0;
		fr (i, 1, n + 1) {
			curr += c[arr[i]][p[j]];
			j++;
			j %= 3;
		}
		if (curr <= ans) {
			idx = x;
			ans = curr;
		}
		x++;
	}

	pr (ans);
	int op[n + 1];
	int j = 0;
	fr (i, 1, n + 1) {
		op[arr[i]] = possible[idx][j] + 1;
		j++;
		j %= 3;
	}
	fr (i, 1, n + 1) {
		cout << op[i] << " ";
	}
	cout << endl;
	return 0;
}
