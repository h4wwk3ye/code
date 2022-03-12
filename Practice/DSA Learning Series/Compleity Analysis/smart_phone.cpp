/*
				C++
				encoding: UTF-8
				Last Modified: 05/Aug/20 06:08:32 PM
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
	int n;
	cin >> n;
	vector< int > arr (n);
	for (auto& i : arr)
		cin >> i;

	sort (arr.begin (), arr.end (), greater< int > ());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max (ans, (i + 1) * arr[i]);
	}
	print (ans);
	return 0;
}