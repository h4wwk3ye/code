/*
				C++
				encoding: UTF-8
				Last Modified: 15/Aug/20 10:00:47 PM
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


// set< pair< int, int > > a, b, c, d, e, f, g;

vector< vector< int > > ans (7, vector< int > (7));
vector< vector< int > > color (7, vector< int > (7));

bool isSafe (vector< vector< int > >& arr, int i, int j, int c) {
	// check each row
	for (int J = 0; J < 7; ++J) {
		if (arr[i][J] == c) return false;
	}

	for (int I = 0; I < 7; ++I) {
		if (arr[I][j] == c) return false;
	}
	return true;
}

bool isEmpty (vector< vector< int > >& arr) {
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (!arr[i][j]) return true;
		}
	}
	return false;
}

pair< int, int > findLocation (vector< vector< int > >& arr) {
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			if (!arr[i][j]) return {i, j};
		}
	}
	return {-1, -1}; // cant reach here just to remove warning
}

bool solve (vector< vector< int > > arr, vector< set< int > > chk) {
	if (!isEmpty (arr)) {
		// check if every condition is satisfied
		for (int i = 1; i <= 7; ++i) {
			if (chk[i].size () != 7) return false;
		}

		// check each row
		for (int i = 0; i < 7; ++i) {
			set< int > s;
			for (int j = 0; j < 7; ++j) {
				s.insert (arr[i][j]);
			}
			if (s.size () != 7) return false;
		}

		// for each col
		for (int i = 0; i < 7; ++i) {
			set< int > s;
			for (int j = 0; j < 7; ++j) {
				s.insert (arr[j][i]);
			}
			if (s.size () != 7) return false;
		}

		ans = arr;
		return true;
	}

	pair< int, int > p = findLocation (arr);

	int i = p.first, j = p.second;

	for (int c = 1; c <= 7; ++c) {
		// only fill if the color is not present and also check for row and col
		if (chk[color[i][j]].find (c) == chk[color[i][j]].end () and isSafe (arr, i, j, c)) {
			arr[i][j] = c;
			int col = color[i][j];
			chk[col].insert (c);

			if (solve (arr, chk)) {
				return true;
			} else {
				auto it = chk[col].lower_bound (c);
				chk[col].erase (it);
				arr[i][j] = 0;
			}
		}
	}
	return false;
}


signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	vector< vector< int > > arr (7, vector< int > (7));
	vector< set< int > > chk (8);
	for (int i = 0; i < 7; ++i)
		for (int j = 0; j < 7; ++j)
			cin >> arr[i][j];

	int cnt = 0;
	map< char, int > already;

	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			char ch;
			cin >> ch;
			int curr;
			if (already.find (ch) == already.end ()) {
				curr = ++cnt;
				already[ch] = cnt;
			} else {
				curr = already[ch];
			}
			color[i][j] = curr;
			if (arr[i][j]) chk[curr].insert (arr[i][j]);
		}
	}

	solve (arr, chk);
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 7; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}