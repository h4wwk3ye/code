/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 08:14:33 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

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
		pair< int, int > arr[n];
		int mnA = 1e9, mnB = 1e9;
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].first;
			mnA = min (mnA, arr[i].first);
		}
		for (int i = 0; i < n; ++i) {
			cin >> arr[i].second;
			mnB = min (mnB, arr[i].second);
		}
		// have to make everything equal to mna and mnb
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			// subtract both first
			int a = arr[i].first - mnA;
			int b = arr[i].second - mnB;
			int x = min (a, b);
			ans += x;
			a -= x;
			b -= x;
			ans += a;
			ans += b;
		}
		print (ans);
	}
	return 0;
}