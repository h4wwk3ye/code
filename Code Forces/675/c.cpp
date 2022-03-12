#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 04/Oct/20 11:31:01 PM
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
	cout << t << ' ';
	print (u, args...);
}

const int mod = static_cast< int > (1e9 + 7), N = static_cast< int > (1e5 + 5);
string n;
int pref[N], dp[N][3]; // not removed anything, removing rn, something removed atleast, removed already
int ans = 0;

int solve (int i, int j, int s) {
	if (i >= n.size ()) {
		ans += s;
		ans %= mod;
		return 0;
	}


	int& ans = dp[i][j];
	if (ans != -1) return ans;

	if (j == 0) {
		// either continue or start selecting
		if (i == n.size () - 1) {
			ans = solve (i + 1, 1, s) % mod;

		} else {
			ans = (solve (i + 1, j, (s * 10 + (n[i] - '0') % mod))) + solve (i + 1, 1, s);
		}
	} else if (j == 1) {
		// stop selecting or continue
		ans = solve (i + 1, j, s) + solve (i + 1, 2, (s * 10 + (n[i] - '0')));
	} else {
		ans = solve (i + 1, j, (s * 10 + (n[i] - '0')));
	}

	return ans;
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n;
	// reverse (n.begin (), n.end ());

	memset (dp, -1, sizeof dp);
	solve (0, 0, 0);
	print (ans);

	return 0;
}