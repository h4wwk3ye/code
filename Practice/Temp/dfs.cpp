/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 02:24:57 PM
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

int N, M;
int ans, cnt;
vector< vector< int > > arr;
vector< vector< bool > > vis;
int X[] = {-1, 1, 0, 0}, Y[] = {0, 0, -1, 1};

bool check (int i, int j) {
	return i >= 0 and i < N and j >= 0 and j < M;
}

void dfs (int i, int j, int val) {
	vis[i][j] = 1;
	cnt++;
	for (int p = 0; p < 4; ++p) {
		int x = i + X[p], y = j + Y[p];
		if (check (x, y) and !vis[x][y] and arr[x][y] == val) {
			dfs (x, y, val);
		}
	}
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> N >> M;
	arr.resize (N, vector< int > (M));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> arr[i][j];

	vis.assign (N, vector< bool > (M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (!vis[i][j]) {
				cnt = 0;
				dfs (i, j, arr[i][j]);
				ans = max (ans, cnt);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}