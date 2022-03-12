/*
				C++
				encoding: UTF-8
				Last Modified: 02/Nov/20 09:01:22 PM
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
		vector< pair< int, int > > arr (n);
		for (auto i = 0; i < n; ++i)
			cin >> arr[i].first;
		for (auto i = 0; i < n; ++i)
			cin >> arr[i].second;
		sort (arr.begin (), arr.end ());
		vector< int > pref (n);
		int p = 0;
		for (auto i = 0; i < n; ++i) {
			pref[i] = p + arr[i].second;
			p = pref[i];
		}
		int ans = arr.back ().first;
		for (auto i = 1; i < n; ++i) {
			ans = min (ans, max (arr[i - 1].first, pref.back () - pref[i - 1]));
		}
		ans = min (ans, pref.back ());
		print (ans);
	}
	return 0;
}