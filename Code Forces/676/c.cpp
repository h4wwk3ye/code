/*
				C++
				encoding: UTF-8
				Last Modified: 18/Oct/20 04:27:55 PM
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
	string s;
	cin >> s;
	int n = static_cast< int > (s.size ());
	vector< pair< char, int > > ans;
	ans.push_back ({'R', 2});

	return 0;
}