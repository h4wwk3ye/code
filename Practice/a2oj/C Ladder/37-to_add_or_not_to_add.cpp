/*
				C++
				encoding: UTF-8
				Last Modified: 28/Oct/20 09:58:36 PM
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
	int n, k;
	cin >> n >> k;
	int arr[n + 1], pref[n + 1] = {0};

	for (auto i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	sort (arr + 1, arr + n + 1);
	for (auto i = 1; i <= n; ++i) {
		pref[i] = arr[i] + pref[i - 1];
	}
	pair< int, int > ans = {1, arr[0]};

	for (auto i = 1; i <= n; ++i) {
		int low = 1, high = i;
		int mx = i;
		while (low <= high) {
			int mid = (low + high) >> 1;
			// try to increase from mid index
			if (arr[i] * (i - mid + 1) - (pref[i] - pref[mid - 1]) <= k) {
				mx = mid;
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}

		if (i - mx + 1 > ans.first) {
			ans = {i - mx + 1, arr[i]};
		}
	}

	print (ans.first, ans.second);
	return 0;
}