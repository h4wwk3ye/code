/*
				C++
				encoding: UTF-8
				Last Modified: 07/Sep/20 10:29:25 AM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

// #define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

int pass (int p) {
	if (p >= 4) return p ^ pass (p >> 1);
	return p & 2;
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	// print (pass (12));
	int arr[] = {1, 2, 3, 4, 5};
	int a, s = 0;
	for (a = 3; a <= 5; ++a) {
		if (a % 2 > 3) s += arr[a - 3];
	}
	print (s);
	return 0;
}