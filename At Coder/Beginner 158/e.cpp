//#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 07/Mar/20 06:17:57 PM
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

const int N = 2e5 + 5;
bitset< 15 > dp[N][2];
int n, p;
string s;

int solve (int i, int j, int f) {
	if (j == s.size ()) return {
			if (f) return i == 0;
			return 0;
		}
	bitset< 15 > temp{i};
	bitset<& ans = dp[j][f];
	if (ans) return ans;
	int x = i * 10 + (s[j] - '0');
	x %= p;
	ans = solve (x, j + 1, 1) + solve (0, j + 1, f)
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	reset (dp, -1);
	cin >> n >> p;
	cin >> s;
	reset (dp, 0);
	int ans = solve (0, 0, 0);
	pr (ans);
	return 0;
}