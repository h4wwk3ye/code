/*
				C++
				encoding: UTF-8
				Last Modified: 04/Jun/22 02:38:59 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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

bool canBePlaced (int i, int j, vector< string >& curr) {
	int n = curr.size ();

	for (int k = 0; k < n; ++k) {
		if (curr[i][k] == 'Q' or curr[k][j] == 'Q') return false;
	}
	for (int k = 0; k < n; ++k) {
		for (int q = 0; q < n; ++q) {
			if (k + q == i + j or k - i == q - j) {
				if (curr[k][q] == 'Q') return false;
			}
		}
	}
	return true;
}

void solve (vector< vector< string > >& ans, vector< string > curr, int n, int cnt) {
	if (cnt == n) {
		ans.push_back (curr);
		return;
	}
    int i = cnt;
	for (int j = 0; j < n; ++j) {
		if (curr[i][j] == '.') {
			if (canBePlaced (i, j, curr)) {
				curr[i][j] = 'Q';
				solve (ans, curr, n, cnt + 1);
				curr[i][j] = '.';
			}
		}
	}
}

vector< vector< string > > solveNQueens (int n) {
	vector< vector< string > > ans;
	vector< string > curr (n, string (n, '.'));

	solve (ans, curr, n, 0);
	return ans;
}

int32_t main () {
	// ios_base::sync_with_stdio (false), cin.tie (nullptr);
	print (solveNQueens (8));
	return 0;
}
