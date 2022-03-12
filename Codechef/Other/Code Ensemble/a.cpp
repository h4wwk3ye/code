/*
				C++
				encoding: UTF-8
				Last Modified: 19/Aug/20 09:02:23 PM
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
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector< int > arr (n);
		for (auto& i : arr)
			cin >> i;

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int x = arr[i] & arr[j];
				if (x == arr[i]) ++ans;
			}
		}
		print (ans);
	}
	return 0;
}