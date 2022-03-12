/*
				C++
				encoding: UTF-8
				Last Modified: 26/Oct/20 06:54:06 PM
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
		int arr[n];
		int a = 0, b = 0;
		bool flag = 0;
		for (auto& i : arr) {
			cin >> i;
			if (flag)
				a += i;
			else
				b += i;
			flag = !flag;
		}
		print (max (a, b));
	}
	return 0;
}