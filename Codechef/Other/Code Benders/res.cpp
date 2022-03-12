//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Mar/20 12:10:54 AM
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
const int N = 11;
int n;
map< int, pii > edges;
ve< ve< int > > poss;
int arr[N], vis[N];
ve< int > graph[N];
void generateAllBinaryStrings (int n, ve< int > com, int i) {
	if (i == n) {
		poss.pb (com);
		return;
	}
	com[i] = 0;
	generateAllBinaryStrings (n, com, i + 1);
	com[i] = 1;
	generateAllBinaryStrings (n, com, i + 1);
}

bool flag = 1;


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> n;

	fr (i, 1, n + 1) cin >> arr[i];

	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap (u, v);
		edges[i] = {u, v};
	}

	ve< int > com (n - 1);
	generateAllBinaryStrings (n - 1, com, 0);
	int ans = 1e9;

	auto dfs = [&](auto&& dfs, int node) -> int {
		vis[node] = 1;
		int curr = arr[node];
		if (arr[node] < 0) flag = 0;
		for (auto& to : graph[node]) {
			if (!vis[to]) {
				curr += dfs (dfs, to);
			}
		}
		return curr;
	};

	for (auto& c : poss) {
		fr (i, 0, n + 1) {
			graph[i].clear ();
			vis[i] = 0;
		}
		int cnt = 0;
		fr (j, 0, len (c)) {
			if (c[j] == 1) {
				auto& edge = edges[j];
				graph[edge.ff].pb (edge.ss);
				graph[edge.ss].pb (edge.ff);
				cnt++;
			}
		}

		bool f = 1;
		fr (i, 1, n + 1) {
			if (!vis[i]) {
				flag = 1;
				int x = dfs (dfs, i);
				if (flag or x < 0) continue;
				f = 0;
				break;
			}
		}
		if (f) {
			ans = min (ans, n - 1 - cnt);
		}
	}
	pr (ans);
	return 0;
}