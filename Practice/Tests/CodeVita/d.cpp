/*
				C++
				encoding: UTF-8
				Last Modified: 15/Aug/20 07:37:26 PM
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
	int m, n;
	cin >> n >> m;
	vector< vector< int > > arr (n, vector< int > (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr[i][j];

	int l = min (n / 2, m / 2);
	vector< int > rot (l);
	for (int i = 0; i < l; ++i) {
		cin >> rot[i];
		int x = m - 2 * i;
		int y = n - 2 * i;
		int mod = 2 * x + 2 * y - 4; // for 4 corners
		rot[i] %= mod;
	}

	int rl = 0, rh = n - 1, cl = 0, ch = m - 1;

	for (int i = 0; i < l; ++i) {
		int a = rl, b = rh, c = cl, d = ch;
		vector< int > tmp;

		for (int j = cl; j <= ch; ++j)
			tmp.push_back (arr[rl][j]);
		rl++;

		for (int j = rl; j <= rh; ++j)
			tmp.push_back (arr[j][ch]);
		ch--;

		for (int j = ch; j >= cl; --j)
			tmp.push_back (arr[rh][j]);
		rh--;

		for (int j = rh; j >= rl; --j)
			tmp.push_back (arr[j][cl]);
		cl++;

		int le = tmp.size ();

		if (!(i & 1)) { // odd as indexing is from 1 in question
			// anticlockwise
			int idx = 0;
			for (int j = c; j <= d; ++j) {
				arr[a][j] = tmp[(idx + rot[i]) % le];
				++idx;
			}
			a++;

			for (int j = a; j <= b; ++j) {
				arr[j][d] = tmp[(idx + rot[i]) % le];
				++idx;
			}
			d--;

			for (int j = d; j >= c; --j) {
				arr[b][j] = tmp[(idx + rot[i]) % le];
				++idx;
			}
			b--;

			for (int j = b; j >= a; --j) {
				arr[j][c] = tmp[(idx + rot[i]) % le];
				++idx;
			}
			c++;
		} else {
			// clockwise
			int idx = 0;
			for (int j = c; j <= d; ++j) {
				arr[a][j] = tmp[(idx - rot[i] + le) % le];
				++idx;
			}
			a++;

			for (int j = a; j <= b; ++j) {
				arr[j][d] = tmp[(idx - rot[i] + le) % le];
				++idx;
			}
			d--;

			for (int j = d; j >= c; --j) {
				arr[b][j] = tmp[(idx - rot[i] + le) % le];
				++idx;
			}
			b--;

			for (int j = b; j >= a; --j) {
				arr[j][c] = tmp[(idx - rot[i] + le) % le];
				++idx;
			}
			c++;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}