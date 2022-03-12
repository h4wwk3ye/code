/*
				C++
				encoding: UTF-8
				Last Modified: 04/Sep/20 09:35:37 PM
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

// https://www.geeksforgeeks.org/smallest-number-greater-than-y-with-sum-of-digits-equal-to-x/

string helper (int d, int s) {
	string ans (d, '0');

	for (int i = d - 1; i >= 0; i--) {
		if (s >= 9) {
			ans[i] = '9';
			s -= 9;
		} else {
			char c = (char)s + '0';
			ans[i] = c;
			s = 0;
		}
	}

	return ans;
}

string findMin (int x, int Y) {
	string y = to_string (Y);

	int n = y.size ();
	vector< int > p (n);

	for (int i = 0; i < n; i++) {
		p[i] = y[i] - '0';
		if (i > 0) p[i] += p[i - 1];
	}

	for (int i = n - 1, k = 0;; i--, k++) {
		int d = 0;

		if (i >= 0) d = y[i] - '0';

		for (int j = d + 1; j <= 9; j++) {
			int r = (i > 0) * p[i - 1] + j;

			if (x - r >= 0 and x - r <= 9 * k) {
				string suf = helper (k, x - r);

				string pre = "";
				if (i > 0) pre = y.substr (0, i);

				char cur = (char)j + '0';
				pre += cur;

				return pre + suf;
			}
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, s;
		cin >> n >> s;
		// try for all the integers with sum less than s and larger than
		int c (0), N (n);
		while (N) {
			c += N % 10;
			N /= 10;
		}
		if (c <= s) {
			print (0);
			continue;
		}
		__int128_t ans = 1e30;
		for (int i = 1; i <= s; ++i) {
			int y = stoll (findMin (i, n));
			if (y < ans) ans = y;
		}
		print ((int)ans - n);
	}
	return 0;
}