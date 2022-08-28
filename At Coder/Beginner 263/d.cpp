/*
				C++
				encoding: UTF-8
				Last Modified: 06/Aug/22 06:23:32 PM
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
	int n, l, r;
	cin >> n >> l >> r;
	vector< int > arr (n);
	for (auto& i : arr)
		cin >> i;

	vector< int > pref (n);
	int c = 0;
	for (int i = 0; i < n; ++i) {
		pref[i] = c + arr[i];
		c = pref[i];
	}
	vector< int > suffix (n);
	c = 0;
	for (int i = n - 1; i >= 0; --i) {
		suffix[i] = c + arr[i];
		c = suffix[i];
	}

	// replace till that point on left where prefix will be more than
	// l * count

	int left = -1;
	for (int i = 0; i < n; ++i) {
		int x = pref[i], y = (i + 1) * l, z = i * l + arr[i];

		if (x > y) {
			left = i;
		}
	}

	int right = n;
	for (int i = n - 1; i >= 0; --i) {
		int x = suffix[i], y = (n - i) * r, z = (n - i - 1) * r + arr[i];
		if (x > y) {
			right = i;
		}
	}

	for (int i = 0; i <= left; ++i)
		pref[i] = (i + 1) * l;
	for (int i = n - 1; i >= right; --i)
		suffix[i] = (n - i) * r;


	if (left != -1) {
		c = pref[left];
		for (int i = left + 1; i < n; ++i) {
			pref[i] = c + arr[i];
			c = pref[i];
		}
	}

	if (right != n) {
		c = suffix[right];
		for (int i = right - 1; i >= 0; --i) {
			suffix[i] = c + arr[i];
			c = suffix[i];
		}
	}


	debug (pref);
	debug (suffix);

	int ans = INT64_MAX;
	for (int i = 0; i < n; ++i) {
		ans = min (ans, pref[i] + suffix[i] - arr[i]);
	}
	print (ans);
	return 0;
}