//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Dec/19 06:34:32 PM
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

ve< ve< int > > graph (20);
int ans, f;
set< int > s[20];

void dfs (int node) {
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;

	fr (i, 1, n + 1) {
		int x;
		cin >> x;
		set< int > tmp;
		fr (j, 0, x) {
			int p, q;
			cin >> p >> q;
			tmp.insert (p);
			if (!q)
				s[i].pb (p);
			else {
				graph[i].pb (p);
			}
		}
		fr (j, 1, n + 1) {
			if (i == j or tmp.find (j) != tmp.end ()) continue;
			graph[i].insert (j);
		}
	}

	fr (i, 1, n + 1) {
		for (int x : graph[i]) {
			dfs (x);
		}
	}
	pr (ans);

	return 0;
}