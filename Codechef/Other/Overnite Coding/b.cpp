//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 08/Feb/20 10:34:50 PM
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

const int N = 1e3 + 5;
char arr[N][N];
int vis[N][N];
int n, m;
set< pii > x;

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;

	auto neighbours = [](int i, int j) -> ve< pii > {
		ve< pii > p = {{i - 1, j - 1},
					   {i - 1, j},
					   {i - 1, j + 1},
					   {i, j - 1},
					   {i, j + 1},
					   {i + 1, j - 1},
					   {i + 1, j},
					   {i + 1, j + 1}};
		return p;
	};

	auto check = [&](int i, int j) -> bool { return i >= 1 and i <= n and j >= 1 and j <= m; };

	auto push = [&](int i, int j) {
		for (auto& p : neighbours (i, j)) {
			if (check (p.ff, p.ss) and arr[p.ff][p.ss] == '.') {
				x.insert ({p.ff, p.ss});
			}
		}
	};

	fr (i, 1, n + 1) fr (j, 1, m + 1) cin >> arr[i][j];
	fr (i, 1, n + 1) fr (j, 1, m + 1) if (arr[i][j] == '#') push (i, j);

	auto bfs = [&](int i, int j) {
		int curr = 1;
		queue< pii > q;
		q.push ({i, j});
		vis[i][j] = 1;
		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();
			for (auto& p : neighbours (node.ff, node.ss)) {
				if (check (p.ff, p.ss) and !vis[p.ff][p.ss] and x.find (p) != x.end ()) {
					q.push (p);
					vis[p.ff][p.ss] = 1;
					curr++;
				}
			}
		}
		return curr;
	};

	int ans = 0;
	fr (i, 1, n + 1) {
		fr (j, 1, m + 1) {
			if (arr[i][j] == '#') {
				for (auto& p : neighbours (i, j)) {
					if (check (p.ff, p.ss) and !vis[p.ff][p.ss] and arr[p.ff][p.ss] == '.') {
						ans = max (ans, bfs (p.ff, p.ss));
					}
				}
			}
		}
	}

	pr (ans);

	return 0;
}