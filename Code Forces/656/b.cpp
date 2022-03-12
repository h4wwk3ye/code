/*
				C++
				encoding: UTF-8
				Last Modified: 17/Jul/20 08:35:55 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int long long

template < typename T > void print (const T& t) {
	cout << t << "\n";
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << " ";
	print (u, args...);
}

signed main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector< int > arr (2 * n);
		for (int i = 0; i < 2 * n; ++i)
			cin >> arr[i];

		vector< int > a;
		set< int > A;

		for (auto& i : arr) {
			if (A.find (i) == A.end ()) {
				a.push_back (i);
				A.insert (i);
			}
		}
		for (auto& i : a)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}