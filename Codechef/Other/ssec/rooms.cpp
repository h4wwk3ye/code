/*
				C++
				encoding: UTF-8
				Last Modified: 17/Sep/20 12:56:28 PM
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

vector< vector< int > > indexes; // store the top left and bottom right coordinates
int tx, ty, bx, by;

vector< int > X = {-1, 1, 0, 0}, Y = {0, 0, 1, -1};

bool check (int x, int y, int n, int m) {
	return x >= 0 and x < n and y >= 0 and y < m;
}

void dfs (int x, int y, vector< vector< char > >& arr, vector< vector< bool > >& vis) {
	vis[x][y] = 1;
	tx = min (tx, x);
	ty = min (ty, y);
	bx = max (bx, x);
	by = max (by, y);

	for (int i = 0; i < 4; ++i) {
		int p = x + X[i];
		int q = y + Y[i];
		if (check (p, q, arr.size (), arr[0].size ()) and !vis[p][q] and arr[p][q] == '.') {
			dfs (p, q, arr, vis);
		}
	}
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);

	int n, m;
	cin >> n >> m;
	vector< vector< char > > arr (n, vector< char > (m));
	vector< vector< bool > > vis (n, vector< bool > (m, false));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!vis[i][j] and arr[i][j] == '.') {
				tx = ty = 1e9;
				bx = by = -1e9;
				dfs (i, j, arr, vis);
				indexes.push_back ({tx, ty, bx, by});
			}
		}
	}


	// make every wall between these indexes empty
	for (auto& idx : indexes) {
		int a = idx[0], b = idx[1], c = idx[2], d = idx[3];
		for (int i = a; i <= c; ++i) {
			for (int j = b; j <= d; ++j) {
				arr[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << arr[i][j];
		cout << '\n';
	}

	return 0;
}