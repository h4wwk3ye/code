#pragma GCC optimize("-O3")
/*
				C++
				encoding: UTF-8
				Last Modified: 24/Aug/20 10:28:18 AM
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

const int N = 1e3 + 5;
char arr[N][N];
int ans[N][N];
int n, m;
int x, y;
int g, h;

bool check (int a, int b) {
	return a >= 0 and a < n and b >= 0 and b < m;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	cin >> n >> m;
	cin >> x >> y;
	x--;
	y--;
	cin >> g >> h;
	g--;
	h--;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			ans[i][j] = 1e9;
		}
	}

	priority_queue< pair< int, pair< int, int > >, vector< pair< int, pair< int, int > > >, greater<> > q;
	q.push ({0, {x, y}});
	ans[x][y] = 0;

	while (!q.empty ()) {
		auto [dis, p] = q.top ();
		q.pop ();

		int a = p.first, b = p.second;

		if (check (a - 1, b) and arr[a - 1][b] == '.' and ans[a - 1][b] > dis) {
			q.push ({dis, {a - 1, b}});
			ans[a - 1][b] = dis;
		}
		if (check (a + 1, b) and arr[a + 1][b] == '.' and ans[a + 1][b] > dis) {
			q.push ({dis, {a + 1, b}});
			ans[a + 1][b] = dis;
		}
		if (check (a, b - 1) and arr[a][b - 1] == '.' and ans[a][b - 1] > dis) {
			q.push ({dis, {a, b - 1}});
			ans[a][b - 1] = dis;
		}
		if (check (a, b + 1) and arr[a][b + 1] == '.' and ans[a][b + 1] > dis) {
			q.push ({dis, {a, b + 1}});
			ans[a][b + 1] = dis;
		}


		for (int i = -2; i <= 2; ++i) {
			for (int j = -2; j <= 2; ++j) {
				if ((i == 0 and j == 0) or (abs (i) == 1 and abs (j) == 0) or (abs (i) == 0 and abs (j) == 1))
					continue;
				int c = a + i, d = b + j;
				if (check (c, d) and arr[c][d] == '.' and ans[c][d] > dis + 1) {
					q.push ({dis + 1, {c, d}});
					ans[c][d] = dis + 1;
				}
			}
		}
	}
	if (ans[g][h] == 1e9) ans[g][h] = -1;
	print (ans[g][h]);

	return 0;
}