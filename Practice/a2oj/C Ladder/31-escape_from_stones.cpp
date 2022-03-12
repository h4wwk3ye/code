/*
				C++
				encoding: UTF-8
				Last Modified: 25/Sep/20 06:12:00 PM
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
	size_t n = s.size ();
	vector< int > a, b;

	for (size_t i = 0; i < n; ++i) {
		if (s[i] == 'r')
			a.push_back (i + 1);
		else
			b.push_back (i + 1);
	}
	for (auto& i : a)
		cout << i << '\n';
	reverse (b.begin (), b.end ());
	for (auto& i : b)
		cout << i << '\n';
	// for_each (a.begin (), a.end (), [] (const int& x) { print (x); });
	// for_each (b.rbegin (), b.rend (), [] (const int& x) { print (x); });
	return 0;
}