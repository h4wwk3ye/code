/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 05:55:55 PM
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

void ans (bool f = 1) {
	print (f ? "Yes" : "No");
	exit (0);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	string s;
	cin >> s;
	map< char, int > mp;
	for (auto& i : s)
		mp[i]++;
	if (s.size () == 1) {
		ans (s[0] == '8');
	}
	if (s.size () == 2) {
		int x = (s[0] - '0') * 10 + (s[1] - '0');
		int y = (s[1] - '0') * 10 + (s[0] - '0');
		bool flag = !(x % 8) or !(y % 8);
		ans (flag);
	}
	int x = 8;
	bool f = false;
	while (x <= 1000) {
		string y = to_string (x);
		while (y.size () < 3)
			y = '0' + y;
		map< char, int > m;
		for (auto& i : y)
			m[i]++;
		bool p = true;
		for (auto& [a, b] : m) {
			if (mp.find (a) == mp.end () or mp[a] < b) {
				p = false;
			}
		}
		if (p) {
			f = true;
			break;
		}
		x += 8;
	}
	ans (f);
	return 0;
}