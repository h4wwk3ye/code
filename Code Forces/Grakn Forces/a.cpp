/*
				C++
				encoding: UTF-8
				Last Modified: 30/Sep/20 08:25:50 PM
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
		int a[n], b[n], c[n];
		for (auto& i : a)
			cin >> i;
		for (auto& i : b)
			cin >> i;
		for (auto& i : c)
			cin >> i;
		vector< int > ans;

		int i = 0;
		while (i < n) {
			if (((!ans.size () or a[i] != ans.back ()) and i != n - 1) or
				(i == n - 1 and a[i] != ans[0] and a[i] != ans.back ())) {
				ans.push_back (a[i++]);
			} else if ((b[i] != ans.back () and i != n - 1) or
					   (i == n - 1 and b[i] != ans[0] and b[i] != ans.back ())) {
				ans.push_back (b[i++]);
			} else {
				ans.push_back (c[i++]);
			}
		}
		for (auto& i : ans)
			cout << i << ' ';
		cout << '\n';
	}
	return 0;
}