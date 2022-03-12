/*
				C++
				encoding: UTF-8
				Modified: <09/Aug/2019 03:10:25 PM>

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

template < typename T, typename... TAIL > void pr (const T& t, TAIL... tail) {
    cout << t << " ";
    pr (tail...);
}

// clang-format on

const int N = 6005;
ve< int > graph[N];
int n, arr[N];
int dp[N][2];

int dfs (int node, int parent) {
	dp[node][0] = 0;		 // not selected
	dp[node][1] = arr[node]; // selected
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node);
		dp[node][1] += dp[to][0];
		dp[node][0] += max (dp[to][0], dp[to][1]);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 1, n + 1) cin >> arr[i];
	fr (i, 0, n) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	dfs (1, 1);
	pr (max (dp[1][0], dp[1][1]));
	return 0;
}
