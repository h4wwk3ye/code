/*
				C++
				encoding: UTF-8
				Last Modified: 04/Sep/20 08:47:53 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, x, y;
		cin >> n >> x >> y;
		vector< int > ans;
		int diff (1);
		while (diff < y - x) {
			if (abs (x - y) % diff == 0 and diff * (n - 1) + x >= y) {
				break;
			}
			++diff;
		}
		n -= 2;
		ans.push_back (x);
		ans.push_back (y);

		// first push the middle elements
		int X (x);
		while (x + diff < y and n) {
			ans.push_back (x + diff);
			n--;
			x += diff;
		}
		x = X;
		while (x - diff > 0 and n) {
			ans.push_back (x - diff);
			n--;
			x -= diff;
		}
		while (n--) {
			ans.push_back (y + diff);
			y += diff;
		}
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}