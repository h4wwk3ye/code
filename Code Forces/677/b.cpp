/*
				C++
				encoding: UTF-8
				Last Modified: 20/Oct/20 08:19:06 PM
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
		for (auto& i : arr)
			cin >> i;
		int ans = 0;
		int p = -1, curr = 0;
		for (int i = 0; i < n; ++i) {
			if (arr[i] == 1) {
				if (p == -1) {
					// nothing found yet
					p = i;
					curr = 0;
				} else {
					ans += curr;
					curr = 0;
				}
			} else {
				curr++;
			}
		}
		print (ans);
	}
	return 0;
}