/*
				C++
				encoding: UTF-8
				Last Modified: 10/Oct/20 10:01:05 PM
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

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;
		int arr[n];
		for (int i = 0; i < n; ++i) {
			if (s[i] == 'W')
				arr[i] = 1;
			else
				arr[i] = 0;
		}

		int wL = 0, wR = 0;
		int bestL = 0, bestWindow = 0;
		int zeroCount = 0;

		while (wR < n) {
			if (zeroCount <= m) {
				if (arr[wR] == 0) zeroCount++;
				wR++;
			}
			if (zeroCount > m) {
				if (arr[wL] == 0) zeroCount--;
				wL++;
			}

			if ((wR - wL >= bestWindow) && (zeroCount <= m)) {
				bestWindow = wR - wL;
				bestL = wL;
			}
		}
		// print (bestL, bestWindow);
		int ans = 0;
		bool p = 0;
		for (int i = 0; i < n; ++i) {
			if (bestL <= i and bestL + bestWindow > i) {
				if (p)
					ans += 2;
				else
					ans++;
				p = 1;
			} else {
				if (arr[i] == 1) {
					if (p)
						ans += 2;
					else
						ans++;
					p = 1;
				} else
					p = 0;
			}
		}
		print (ans);
	}
	return 0;
}