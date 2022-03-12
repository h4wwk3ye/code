//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 22/Mar/20 10:59:55 AM
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

map< string, int > dp;

int solve (int m, ve< int >& pos, ve< ve< int > >& arr) {
	if (m == 0) return 0;
	string s;
	for (auto& i : pos) {
		s += i - '0';
	}
	s += m - '0';
	if (dp.find (s) != dp.end ()) return dp[s];
	int ans = 0;
	fr (i, 0, len (arr)) {
		if (pos[i] >= 0) {
			pos[i]--;
			ans = max (ans, arr[i][pos[i] + 1] + solve (m - 1, pos, arr));
			pos[i]++;
		}
	}
	dp[s] = ans;
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	fr (i, 1, tc + 1) {
		cout << "Case #" << i << ": ";
		int n, k, m;
		cin >> n >> k >> m;
		ve< ve< int > > arr (n, ve< int > (k));
		dp.clear ();
		fr (i, 0, n) {
			fr (j, 0, k) {
				cin >> arr[i][j];
			}
		}

		fr (i, 0, n) reverse (all (arr[i]));

		ve< int > pos (n, k - 1);

		int ans = solve (m, pos, arr);
		pr (ans);
	}
	return 0;
}