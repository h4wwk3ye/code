/*
				C++
				encoding: UTF-8
				Last Modified: 31/Aug/20 01:00:09 PM
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
	int n;
	cin >> n;
	vector< int > arr (n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort (arr.begin (), arr.end ());

	__int128_t ans = 1e18;
	int r = 1e5 / n;
	auto abs = [] (__int128_t a) { return a >= 0 ? a : -a; };

	for (int i = 1; i <= r; ++i) {
		__int128_t curr = 0;
		__int128_t x = 1;
		for (auto& j : arr) {
			curr += abs (j - x);
			if (curr > ans) break;
			x = x * i;
		}
		if (curr < ans) ans = curr;
	}

	print ((long long)ans);

	return 0;
}