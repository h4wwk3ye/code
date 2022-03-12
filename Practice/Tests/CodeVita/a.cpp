/*
				C++
				encoding: UTF-8
				Last Modified: 15/Aug/20 05:11:38 PM
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

int solve (vector< vector< char > >& b, int n) {
	// try for each row
	vector< int > x (n);
	for (int j = 0; j < n; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i][j] == 'D') cnt++;
		}
		x[j] = cnt;
	}
	// now try for max square wall
	// n^3 will work
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		// try for all possible squares
		for (int j = n - i; j > 0; --j) {
			// next j should have atleast a min of j
			int mn = 1e4;
			for (int k = 1; k <= j; ++k) {
				mn = min (mn, x[i + k - 1]);
				if (mn < j) break;
			}
			if (mn >= j and mn != 1e4) {
				ans = max (ans, j);
				break;
			}
		}
	}

	return ans;
}

void rotateMatrix (vector< vector< char > >& arr, int n) {
	for (int i = 0; i < n / 2; ++i) {
		for (int j = i; j < n - i - 1; ++j) {
			char tmp = arr[i][j];
			arr[i][j] = arr[j][n - i - 1];
			arr[j][n - i - 1] = arr[n - i - 1][n - j - 1];
			arr[n - i - 1][n - j - 1] = arr[n - j - 1][i];
			arr[n - j - 1][i] = tmp;
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	vector< vector< char > > arr (n, vector< char > (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	// try from all four directions

	int ans = 0;
	for (int i = 0; i < 4; ++i) {
		// rotate by 90 degrees
		rotateMatrix (arr, n);
		ans = max (ans, solve (arr, n));
	}

	cout << ans;
	return 0;
}