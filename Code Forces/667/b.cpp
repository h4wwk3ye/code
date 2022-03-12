/*
				C++
				encoding: UTF-8
				Last Modified: 04/Sep/20 08:27:56 PM
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

	auto check = [&] (int mid) {

	};

	while (tc--) {
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;

		int low = max (a - n, x), high = a; // the lowest a can reach
		int ans = 1e18;

		while (low <= high) {
			int mid = (low + high) >> 1;
			int z = n - (a - mid);
			// if b can take more move right ;
			int bVal = max (b - z, y);
			ans = min (ans, mid * bVal);

			if (b - z < y)
				high = mid - 1;
			else
				low = mid + 1;
		}

		low = max (b - n, y), high = b;
		while (low <= high) {
			int mid = (low + high) >> 1;
			int z = n - (b - mid);
			// if a can take more move right ;
			int aVal = max (a - z, x);
			ans = min (ans, mid * aVal);

			if (a - z < x)
				high = mid - 1;
			else
				low = mid + 1;
		}
		print (ans);
	}
	return 0;
}