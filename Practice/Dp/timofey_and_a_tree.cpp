/*
				C++
				encoding: UTF-8
				Modified: <13/Aug/2019 01:08:31 PM>

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

int n;
const int N = 1e5 + 5;
ve< int > graph[N];
int arr[N];
bool flag;

void dfs (int node, int parent, int c) {
	if (arr[node] != c) {
		flag = false;
		return;
	}
	for (int to : graph[node]) {
		if (to == parent) continue;
		dfs (to, node, c);
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	fr (i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		graph[u].pb (v);
		graph[v].pb (u);
	}
	fr (i, 1, n + 1) cin >> arr[i];

	int root1 = 0, root2 = 0;
	fr (i, 1, n + 1) {
		for (int j : graph[i]) {
			if (arr[j] != arr[i]) {
				root1 = i;
				root2 = j;
				break;
			}
		}
	}
	if (root1 == 0) {
		pr ("YES\n1");
		return 0;
	}
	flag = true;
	for (int node : graph[root1]) {
		dfs (node, root1, arr[node]);
		if (!flag) break;
	}
	if (flag) {
		pr ("YES");
		pr (root1);
		return 0;
	}

	flag = true;
	for (int node : graph[root2]) {
		dfs (node, root2, arr[node]);
		if (!flag) break;
	}
	if (flag) {
		pr ("YES");
		pr (root2);
		return 0;
	}

	pr ("NO");
	return 0;
}
