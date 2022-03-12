//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 11/Apr/20 07:25:50 AM
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
ve< ve< int > > arr (N + 1, ve< int > (N + 1));
int vis[N][N];

ve< pii > ans;
void solve (int i, int j, int n, ve< pii > t) {
	if (n < 0) {
		return;
	}
	if (n == 0) {
		ans = t;
		return;
	}
	if (ans.size ()) return;
	if (i < 0 or j < 0 or i >= N or j > i) return;
	if (vis[i][j]) return;
	vis[i][j] = 1;
	n -= arr[i][j];
	t.push_back ({i, j});
	solve (i - 1, j - 1, n, t);
	solve (i - 1, j, n, t);
	solve (i, j - 1, n, t);
	solve (i, j + 1, n, t);
	solve (i + 1, j + 1, n, t);
	solve (i + 1, j, n, t);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	for (int line = 0; line < N; line++) {
		for (int i = 0; i <= line; i++) {
			if (line == i || i == 0)
				arr[line][i] = 1;
			else
				arr[line][i] = arr[line - 1][i - 1] + arr[line - 1][i];
		}
	}

	int tc;
	cin >> tc;
	fr (TC, 1, tc + 1) {
		cout << "Case #" << TC << ":\n";
		int n;
		cin >> n;
		reset (vis, 0);
		ans.clear ();

		solve (0, 0, n, {});
		for (auto& x : ans)
			pr (x.ff + 1, x.ss + 1);
	}

	return 0;
}