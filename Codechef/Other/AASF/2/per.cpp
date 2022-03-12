#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 21/Mar/20 03:40:10 PM
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

set< int > s[21];
int n, m;
map< pair< int, string >, int > dp;

int solve (int i, string j) {
	if (i == n + 1) {
		fr (k, 1, n + 1) {
			int x = j[k - 1] - '0';
			if (s[k].find (x) != s[k].end ()) return 0;
		}
		return 1;
	}
	if (dp.find ({i, j}) != dp.end ()) return dp[{i, j}];
	int y = 0;
	fr (k, 1, n + 1) {
		bool f = 0;
		char x = k + '0';
		for (auto& p : j) {
			if (p == x) {
				f = 1;
				break;
			}
		}
		if (f) continue;
		y += solve (i + 1, j + x);
	}
	return dp[{i, j}] = y;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> n >> m;
	if (m == 0) {
		int ans = 1;
		fr (i, 1, n + 1) ans *= i;
		pr (ans);
		return 0;
	} else if (m == 1) {
		int ans = 1;
		fr (i, 1, n + 1) ans *= i;
		int x = 1;
		fr (i, 1, n) x *= i;
		pr (ans - x);
		return 0;
	}

	fr (i, 0, m) {
		int x, y;
		cin >> x >> y;
		s[y].insert (x);
	}

	int ans = solve (1, "");
	pr (ans);
	return 0;
}