/*
				C++
				encoding: UTF-8
				Last Modified: 27/Mar/22 06:15:55 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
	int n;
	long double p;
	cin >> n >> p;
	// no of mood switches should be even
	cout << setprecision (10);
	long double prob = 1.0;
	while (n) {
		if (n & 1) prob = prob * (1 - p) + (1 - prob) * p;
		p = p * (1 - p) + (1 - p) * p;
		n >>= 1;
	}
	print (prob);
	return 0;
}