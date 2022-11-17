/*
				C++
				encoding: UTF-8
				Last Modified: 30/Aug/22 09:29:47 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettyprint.hpp>
#else
#	define debug(...)
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
		vector< string > arr (2);
		cin >> arr[0];
		cin >> arr[1];

		bool flag = true;
		for (int i = 0; i < n; ++i) {
			if ((arr[0][i] == arr[1][i]) or (arr[0][i] == 'G' and arr[1][i] == 'B') or
				(arr[0][i] == 'B' and arr[1][i] == 'G'))
				continue;
			flag = false;
		}

		print (flag ? "YES" : "NO");
	}
	return 0;
}