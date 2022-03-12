/*
				C++
				encoding: UTF-8
				Last Modified: 29/Aug/20 05:36:43 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

const int N = 1e3 + 5;
int dp[N][N];
string s, t;

int solve (int i, int j) {
	if (j == t.size ()) return 0;
	if (i == s.size ()) return 1e9;
	int& ans = dp[i][j];
	if (ans != -1) return ans;

	// either make this character same or start from beginning

	if (s[i] == t[j]) {
		ans = min (solve (i + 1, j + 1), solve (i + 1, 0));
	} else {
		ans = min (solve (i + 1, j + 1) + 1, solve (i + 1, 0));
	}
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	cin >> s >> t;
	memset (dp, -1, sizeof dp);

	print (solve (0, 0));

	return 0;
}