/*
				C++
				encoding: UTF-8
				Last Modified: 23/Oct/20 06:44:01 PM
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
	cout << fixed << setprecision (10);
	int n;
	cin >> n;
	vector< int > arr = {0};
	int sum = 0;
	map< int, int > mp; // all the increment points
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int a, x;
			cin >> a >> x;
			mp[a] += x;
			sum += a * x;
		} else if (t == 2) {
			int x;
			cin >> x;
			arr.push_back (x);
			sum += x;
		} else {
			int l = arr.size ();
			int x = arr.back ();
			x += mp[l];
			sum -= x;
			mp[l - 1] += mp[l];
			mp.erase (l);
			arr.pop_back ();
		}

		long double ans = static_cast< long double > (sum) / arr.size ();
		print (ans);
	}

	return 0;
}