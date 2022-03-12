/*
				C++
				encoding: UTF-8
				Last Modified: 30/Sep/20 11:00:16 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n, l;
		cin >> n >> l;
		vector< int > arr (n + 2);
		arr[0] = 0;
		for (int i = 1; i < n + 1; ++i)
			cin >> arr[i];
		arr[n + 1] = l;
		// print (arr);
		cout << setprecision (10) << fixed;

		vector< long double > a (n + 2), b (n + 2); // time taken by each to reach i
		int p = 0, s = 1;
		long double prv = 0;
		for (int i = 1; i <= n + 1; ++i) {
			int d = arr[i] - p;
			long double t = d / (s * 1.0);
			s++;
			a[i] = t + prv;
			prv = a[i];
			p = arr[i];
		}

		p = l, s = 1, prv = 0;
		for (int i = n; i >= 0; --i) {
			int d = p - arr[i];
			long double t = d / (s * 1.0);
			s++;
			b[i] = t + prv;
			prv = b[i];
			p = arr[i];
		}
		// print (a, b);
		// the point at which both will have atleast the same time
		int x, y = n;
		for (int i = 1; i <= n + 1; ++i) {
			if (a[i] >= b[i]) {
				y = i;
				break;
			}
		}
		x = y - 1;
		// between x and y
		// print (x, y);
		long double ans = a[x];

		if (a[y] == b[y]) {
			// at same time
			print (a[y]);
			continue;
		}

		// a at speed of x and b at n - x
		long double d = arr[y] - arr[x];
		// print (ans, d, b[x] - a[x], (b[x] - a[x]) * (x + 1));
		if (a[x] < b[y]) {
			d -= (b[y] - a[x]) * (x + 1);
			ans += b[y] - a[x];
		} else {
			ans = b[y];
			ans += a[x] - b[y];
			d -= (a[x] - b[y]) * (n + 2 - y);
			// y--;
		}
		// print (ans, d);
		int rl = x + 1 + (n + 2 - y);
		ans += d / rl;
		print (ans);
	}
	return 0;
}