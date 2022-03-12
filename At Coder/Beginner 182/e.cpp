/*
				C++
				encoding: UTF-8
				Last Modified: 08/Nov/20 07:03:04 PM
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
	int h, w, n, m;
	cin >> h >> w >> n >> m;

	map< int, set< int > > row, col, brow, bcol;
	int ans = 0;
	for (auto i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		row[a].insert (b);
		col[b].insert (a);
		ans++;
	}
	for (auto i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		brow[a].insert (b);
		bcol[b].insert (a);
	}

	// left and top only for the first bulb on the row
	for (auto& [i, bulbs] : row) {
		auto it = bulbs.begin ();
		int j = *it;

		// block/boundary on top
		if (bcol.find (j) == bcol.end ()) {
			ans += i - 1;
		} else {
			auto p = bcol[j].lower_bound (i);
			if (p == bcol[j].end ()) {
				ans += i - 1;
			} else {
				--p;
				int x = *p;
				ans += (i - x - 1);
			}
		}


		if (brow.find (i) == brow.end ()) {
			ans += j - 1;
		} else {
			auto p = brow[i].lower_bound (j);
			if (p == brow[i].end ()) {
				ans += j - 1;
			} else {
				--p;
				int x = *p;
				ans += (j - x - 1);
			}
		}
		while (it != bulbs.end ()) {
			// boundary/bulb/block
			j = *it;
			it++;

			int x = w + 1;
			if (it != bulbs.end ()) {
				x = min (x, *it);
			}
			if (brow.find (i) != brow.end ()) {
				auto p = brow[i].lower_bound (j);
				if (p != brow[i].end ()) {
					x = min (x, *p);
				}
			}

			ans += x - j - 1;
			x = h + 1;
			auto q = col[j].lower_bound (i);
			++q;
			if (q != col[j].end ()) {
				x = min (x, *q);
			}

			auto p = bcol[j].lower_bound (i);
			if (p != bcol[j].end ()) {
				x = min (x, *p);
			}
			ans += x - i - 1;
		}
		print (ans);
	}
	print (ans);
	return 0;
}