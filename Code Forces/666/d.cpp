/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/20 10:04:50 PM
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
		int n;
		cin >> n;
		int arr[n];
		int s = 0, mx = 0;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
			s += arr[i];
			mx = max (mx, arr[i]);
		}
		int y = s - mx;
		if (n == 1) {
			print ("T");
			continue;
		}
		if ((!(n & 1) and !(s & 1)) or (n & 1 and s & 1))
			print ("HL");
		else
			print ("T");
	}
	return 0;
}