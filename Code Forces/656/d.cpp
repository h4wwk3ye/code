/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jul/20 09:21:25 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}


int solve (string& s, char c, int l, int r) {
	if (l == r) return s[l] != c;

	// either make first half or second half same
	int a = 0, b = 0;
	int mid = (l + r + 1) >> 1;

	for (int i = l; i < mid; ++i) {
		if (s[i] != c) a++;
	}

	for (int i = mid; i <= r; ++i) {
		if (s[i] != c) b++;
	}

	int ans = min (a + solve (s, c + 1, mid, r), b + solve (s, c + 1, l, mid - 1));
	return ans;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		print (solve (s, 'a', 0, n - 1));
	}
	return 0;
}