/*
				C++
				encoding: UTF-8
				Last Modified: 24/Sep/20 09:01:01 PM
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
		int n, q;
		cin >> n >> q;
		vector< int > arr (n);
		for (auto& i : arr)
			cin >> i;

		if (n == 1) {
			print (arr[0]);
			continue;
		}
		if (n == 2) {
			print (max (arr[0], arr[1]));
			continue;
		}

		// pick each pair of local maxima and minima

		vector< int > z;
		bool m{false};

		for (size_t i = 1; i < n; i++) {
			if (!m) {
				// selecting maxima
				if (arr[i] < arr[i - 1]) {
					// previous was maxima
					z.push_back (arr[i - 1]);
					m = 1;
				}
			} else {
				// minima
				if (arr[i] > arr[i - 1]) {
					z.push_back (arr[i - 1]);
					m = 0;
				}
			}
		}
		if (!m and arr.back () >= arr[n - 2]) z.push_back (arr.back ());

		if (!(z.size () & 1)) z.pop_back ();

		int ans{0};
		for (size_t i = 0; i < z.size (); ++i) {
			if (i & 1)
				ans -= z[i];
			else
				ans += z[i];
		}
		print (ans);
	}

	return 0;
}