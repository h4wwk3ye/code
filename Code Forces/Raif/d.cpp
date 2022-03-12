/*
				C++
				encoding: UTF-8
				Last Modified: 17/Oct/20 09:02:52 PM
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
	int arr[n];
	set< int > s;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i]) s.insert (i);
	}
	print (s);
	vector< pair< int, int > > ans;
	vector< int > row (n, -1);
	int mn = n;
	while (!s.empty ()) {
		auto it = s.begin ();
		int x = *it;
		s.erase (it);
		if (arr[x] == 1) {
			ans.push_back ({mn--, x + 1});
		} else if (arr[x] == 2) {
			ans.push_back ({mn++, x + 1});
			it = s.begin ();
			int y = *it;
		}
	}
	print (ans);
	return 0;
}