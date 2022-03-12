/*
				C++
				encoding: UTF-8
				Last Modified: 12/Nov/20 11:37:05 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

const int N = static_cast< int > (1e5) + 5;
vector< int > graph[N];
array< int, N > val, goal;

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	for (auto i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back (v);
		graph[v].push_back (u);
	}

	for (auto i = 1; i <= n; ++i)
		cin >> val[i];
	for (auto i = 1; i <= n; ++i)
		cin >> goal[i];

	{ int x; }
	{ int y = 1; }

	// check if current node is toggled or not
	// use different flags for even and odd lengths
	int ans = 0;
	vector< int > arr;
	auto dfs = [&] (int node, int parent, bool depth, bool even, bool odd, auto&& dfs) -> void {
		int value = val[node];
		if (depth) {
			if (odd) value ^= 1;
			if (value != goal[node]) odd = !odd;
		} else {
			if (even) value ^= 1;
			if (value != goal[node]) even = !even;
		}
		for (auto& to : graph[node]) {
			if (to == parent) continue;
			dfs (to, node, !depth, even, odd, dfs);
		}
		if (value != goal[node]) {
			ans++;
			arr.push_back (node);
		}
	};
	dfs (1, 1, 0, 0, 0, dfs);
	print (ans);
	for (auto& node : arr)
		print (node);
	return 0;
}