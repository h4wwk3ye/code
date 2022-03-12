/*
				C++
				encoding: UTF-8
				Last Modified: 27/Sep/20 10:19:25 PM
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
		int n;
		cin >> n;
		vector< int > arr (n);
		int mx = 0;
		map< int, int > mp;
		for (auto& i : arr) {
			cin >> i;
			mp[i]++;
			mx = max (mx, mp[i]);
		}
	}
	return 0;
}