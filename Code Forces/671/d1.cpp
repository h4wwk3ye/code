/*
				C++
				encoding: UTF-8
				Last Modified: 24/Sep/20 07:47:09 PM
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
	size_t n;
	cin >> n;
	vector< int > arr (n);
	for (auto& i : arr)
		cin >> i;
	sort (arr.begin (), arr.end ());
	int low{0}, high{n - 1}, ans;

	while (low <= high) {
		int mid{(low + high) >> 1};
	}

	return 0;
}