/*
				C++
				encoding: UTF-8
				Last Modified: 19/Aug/20 09:28:09 PM
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
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int l = 0, r = 0, curr = 0, mx = 0;
	set< int > s;
	while (l < n and r < n) {
		if (s.find (arr[r]) == s.end ()) {
			s.insert (arr[r]);
			curr += arr[r];
			++r;
		} else {
			s.erase (arr[l]);
			curr -= arr[l];
			++l;
		}
		mx = max (mx, curr);
	}
	print (mx);
	return 0;
}