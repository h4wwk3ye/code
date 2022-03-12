/*
				C++
				encoding: UTF-8
				Last Modified: 01/Nov/20 06:22:26 PM
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
	int n, m;
	cin >> n >> m;
	vector< int > H (n), W (m);
	for (auto i = 0; i < n; ++i)
		cin >> H[i];
	for (auto i = 0; i < m; ++i)
		cin >> W[i];
	sort (H.begin (), H.end ());
	sort (W.begin (), W.end ());
	vector< int > odd (n, 0), even (n, 0);
	even[0] = H[0];
	for (auto i = 1; i < n; ++i) {
		odd[i] = odd[i - 1];
		even[i] = even[i - 1];
		if (i & 1) {
			odd[i] += H[i];
		} else {
			even[i] += H[i];
		}
	}
	int ans = static_cast< int > (1e18);
	for (auto i = 0; i < n; ++i) {
		// try to make pair here with closest w
		auto j = lower_bound (W.begin (), W.end (), H[i]);
		// 3 closest values
		if (j == W.end ()) --j;
		int curr = 1e10;
		curr = min (curr, abs (*j - H[i]));
		if (j != W.begin ()) {
			--j;
			curr = min (curr, abs (*j - H[i]));
			++j;
		}
		if (j != W.end ()) {
			++j;
			curr = min (curr, abs (*j - H[i]));
		}

		if (!(i & 1)) {
			if (i - 1 >= 0) {
				curr -= even[i - 1];
				curr += odd[i - 1];
			}
			if (i + 1 < n) {
				curr += odd[i];
				curr -= even[i];
				curr -= odd.back ();
				curr += even.back ();
			}
		} else {
			if (i - 2 >= 0) {
				curr -= even[i - 2];
				curr += odd[i - 2];
			}
			curr += H[i + 1] - H[i - 1];
			curr += even.back ();
			curr -= odd.back ();
			curr += odd[i + 1];
			curr -= even[i + 1];
		}
		ans = min (ans, curr);
	}
	print (ans);
	return 0;
}