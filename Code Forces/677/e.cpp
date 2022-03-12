/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 09:03:55 PM
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
	int n;
	cin >> n;
	vector< int > fact (21, 1);
	for (int i = 1; i < 21; ++i)
		fact[i] = fact[i - 1] * i;
	int ans = fact[n] / ((n / 2) * n);
	print (ans);
	return 0;
}