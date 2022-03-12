/*
				C++
				encoding: UTF-8
				Last Modified: 09/Sep/20 09:20:13 PM
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

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	int n = s.size ();
	vector< vector< bool > > dp (n, vector< bool > (n, false)); // true if s[i: j] is palindrome

	for (int i = 0; i < n; ++i) // 1 length substring
		dp[i][i] = true;

	// check for all substrings of length 2

	for (int i = 0; i < n - 1; ++i) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
		}
	}

	for (int l = 3; l <= n; ++l) { // substrings of length l
		for (int i = 0; i < n - l + 1; ++i) {
			int j = i + l - 1;
			if (dp[i + 1][j - 1] and s[i] == s[j]) {
				dp[i][j] = 1;
			}
		}
	}

	int p = 0, q = 0;
	bool ans = false;
	// now try for the solution using dp table

	while (p < n - 2) {
		if (dp[0][p]) {
			// try for second substring from p + 1
			for (int i = p + 1; i < n - 1; ++i) {
				if (dp[p + 1][i] and dp[i + 1][n - 1]) {
					ans = true;
					q = i;
					break;
				}
			}
		}
		if (ans) break;
		++p;
	}

	if (!ans) {
		cout << "Impossible";
	} else {
		string ans;
		for (int i = 0; i <= p; ++i)
			ans += s[i];
		cout << ans << '\n';
		ans = "";
		for (int i = p + 1; i <= q; ++i)
			ans += s[i];
		cout << ans << '\n';
		ans = "";
		for (int i = q + 1; i < n; ++i)
			ans += s[i];
		cout << ans;
	}

	return 0;
}