/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 08:15:13 PM
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
	vector< string > arr;
	for (int i = 1; i <= 9; ++i) {
		string s = to_string (i);
		while (stoll (s) <= 10000) {
			arr.push_back (s);
			s += (i + '0');
		}
	}
	vector< int > cnt (arr.size (), 0);
	for (int i = 0; i < arr.size (); ++i) {
		cnt[i] = arr[i].size ();
	}
	int p = 0;
	for (auto& i : cnt) {
		i += p;
		p = i;
	}
	// print (cnt);
	while (tc--) {
		int x;
		cin >> x;
		string s = to_string (x);
		for (int i = 0; i < arr.size (); ++i) {
			if (arr[i] == s) {
				// print (i, arr[i], s, cnt[i]);
				print (cnt[i]);
				break;
			}
		}
	}
	return 0;
}