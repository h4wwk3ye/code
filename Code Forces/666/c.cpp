/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/20 09:52:46 PM
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

int gcd (int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcd (b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

pair< int, int > find_any_solution (int a, int b, int c) {
	int x0, y0, g;
	g = gcd (abs (a), abs (b), x0, y0);

	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return {x0, y0};
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int n;
	cin >> n;
	vector< int > arr (n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n == 1) {
		print (1, 1);
		print (-1 * arr[0]);
		print (1, 1);
		print (0);
		print (1, 1);
		print (0);
		return 0;
	}

	print (1, 1);
	print (-1 * arr[0]);
	// make everyindex a multiple of n
	print (2, n);
	for (int i = 1; i < n; ++i) {
		auto [x, y] = find_any_solution (n, -(n - 1), arr[i]);
		cout << ((n - 1) * y) << ' ';
		arr[i] += (n - 1) * y;
	}
	cout << '\n';
	print (1, n);
	cout << 0 << ' ';
	for (int i = 1; i < n; ++i)
		cout << -arr[i] << ' ';
	cout << '\n';


	return 0;
}