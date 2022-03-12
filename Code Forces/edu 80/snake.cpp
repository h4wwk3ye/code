//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 15/Jan/20 09:45:54 PM
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


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int r, c;
		cin >> r >> c;
		int arr[r][c], vis[r][c];
		setprecision (3);
		long double dis[r][c];

		int x, y, m, n;
		fr (i, 0, r) fr (j, 0, c) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) x = i, y = j;
			if (arr[i][j] == 9) m = i, n = j;
			vis[i][j] = 0;
		}

		auto neighbours = [&](int a, int b) {
			ve< pii > p = {{a - 1, b},
						   {a - 1, b + 1},
						   {a, b - 1},
						   {a, b + 1},
						   {a + 1, b - 1},
						   {a + 1, b},
						   {a + 1, b + 1},
						   {a - 1, b - 1}};
			return p;
		};

		auto check = [&](int a, int b) -> bool { return a >= 0 and a < r and b >= 0 and b < c; };

		queue< pii > q;
		q.push ({x, y});
		dis[x][y] = 0;
		vis[x][y] = 1;
		while (!q.empty ()) {
			auto node = q.front ();
			q.pop ();
			for (auto& p : neighbours (node.ff, node.ss)) {
				if (check (p.ff, p.ss) and !vis[p.ff][p.ss]) {
					if ((p.ff + p.ss == node.ff + node.ss) or (p.ff - p.ss == node.ff - node.ss)) {
						dis[p.ff][p.ss] = 1.414 + dis[node.ff][node.ss];
					} else {
						dis[p.ff][p.ss] = 1 + dis[node.ff][node.ss];
					}
					vis[p.ff][p.ss] = 1;
					q.push ({p.ff, p.ss});
				}
			}
		}
		long double ans = dis[m][n];
		string s = to_string (ans);
		int i;
		int cnt = 0;
		bool f = 0;
		fr (j, 0, len (s)) {
			if (s[j] == '.')
				f = 1;
			else {
				if (f) cnt++;
				if (cnt >= 4) s[j] = '#';
			}
		}

		while (len (s) and s.back () == '#')
			s.pop_back ();
		while (len (s) and s.back () == '0')
			s.pop_back ();
		if (len (s) and s.back () == '.') s.pop_back ();
		pr (s);
	}
	return 0;
}