//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 19/Jan/20 03:49:09 PM
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

const int N = 1e5 + 5;
unordered_map< int, unordered_map< int, ve< int > > > mp;
int dp[N][8];
int n, m;

int solve (int i, int j) {
	if (i > n) return 0;
	int& ans = dp[i][j];
	if (ans != -1) return ans;
	ans = -1e18;
	fr (k, 1, 8) {
		if (k != j) {
			if (mp[i][k].size ()) {
				ans = max (ans, mp[i][k].back () + solve (i + 1, k));
			}
		}
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	auto init = [&]() -> void {
		mp.clear ();
		fr (i, 0, n + 5) fr (j, 0, 8) dp[i][j] = -1;
	};

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		init ();
		fr (i, 0, m) {
			int b, c, v;
			cin >> b >> c >> v;
			mp[b][c].pb (v);
		}
		fr (i, 1, n + 1) {
			fr (j, 1, 8) {
				sort (all (mp[i][j]));
			}
		}
		int ans = solve (1, 0);
		ans = max (-1LL, ans);
		pr (ans);
	}
	return 0;
}